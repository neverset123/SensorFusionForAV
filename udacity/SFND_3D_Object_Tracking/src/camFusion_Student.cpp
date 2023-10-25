
#include <iostream>
#include <algorithm>
#include <numeric>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "camFusion.hpp"
#include "dataStructures.h"
#include <bits/stdc++.h>
#include <numeric>

using namespace std;


// Create groups of Lidar points whose projection into the camera falls into the same bounding box
void clusterLidarWithROI(std::vector<BoundingBox> &boundingBoxes, std::vector<LidarPoint> &lidarPoints, float shrinkFactor, cv::Mat &P_rect_xx, cv::Mat &R_rect_xx, cv::Mat &RT)
{
    // loop over all Lidar points and associate them to a 2D bounding box
    cv::Mat X(4, 1, cv::DataType<double>::type);
    cv::Mat Y(3, 1, cv::DataType<double>::type);

    for (auto it1 = lidarPoints.begin(); it1 != lidarPoints.end(); ++it1)
    {
        // assemble vector for matrix-vector-multiplication
        X.at<double>(0, 0) = it1->x;
        X.at<double>(1, 0) = it1->y;
        X.at<double>(2, 0) = it1->z;
        X.at<double>(3, 0) = 1;

        // project Lidar point into camera
        Y = P_rect_xx * R_rect_xx * RT * X;
        cv::Point pt;
        // pixel coordinates
        pt.x = Y.at<double>(0, 0) / Y.at<double>(2, 0); 
        pt.y = Y.at<double>(1, 0) / Y.at<double>(2, 0); 

        vector<vector<BoundingBox>::iterator> enclosingBoxes; // pointers to all bounding boxes which enclose the current Lidar point
        for (vector<BoundingBox>::iterator it2 = boundingBoxes.begin(); it2 != boundingBoxes.end(); ++it2)
        {
            // shrink current bounding box slightly to avoid having too many outlier points around the edges
            cv::Rect smallerBox;
            smallerBox.x = (*it2).roi.x + shrinkFactor * (*it2).roi.width / 2.0;
            smallerBox.y = (*it2).roi.y + shrinkFactor * (*it2).roi.height / 2.0;
            smallerBox.width = (*it2).roi.width * (1 - shrinkFactor);
            smallerBox.height = (*it2).roi.height * (1 - shrinkFactor);

            // check wether point is within current bounding box
            if (smallerBox.contains(pt))
            {
                enclosingBoxes.push_back(it2);
            }

        } // eof loop over all bounding boxes

        // check wether point has been enclosed by one or by multiple boxes
        if (enclosingBoxes.size() == 1)
        { 
            // add Lidar point to bounding box
            enclosingBoxes[0]->lidarPoints.push_back(*it1);
        }

    } // eof loop over all Lidar points
}

/* 
* The show3DObjects() function below can handle different output image sizes, but the text output has been manually tuned to fit the 2000x2000 size. 
* However, you can make this function work for other sizes too.
* For instance, to use a 1000x1000 size, adjusting the text positions by dividing them by 2.
*/
void show3DObjects(std::vector<BoundingBox> &boundingBoxes, cv::Size worldSize, cv::Size imageSize, bool bWait)
{
    // create topview image
    cv::Mat topviewImg(imageSize, CV_8UC3, cv::Scalar(255, 255, 255));

    for(auto it1=boundingBoxes.begin(); it1!=boundingBoxes.end(); ++it1)
    {
        // create randomized color for current 3D object
        cv::RNG rng(it1->boxID);
        cv::Scalar currColor = cv::Scalar(rng.uniform(0,150), rng.uniform(0, 150), rng.uniform(0, 150));

        // plot Lidar points into top view image
        int top=1e8, left=1e8, bottom=0.0, right=0.0; 
        float xwmin=1e8, ywmin=1e8, ywmax=-1e8;
        for (auto it2 = it1->lidarPoints.begin(); it2 != it1->lidarPoints.end(); ++it2)
        {
            // world coordinates
            float xw = (*it2).x; // world position in m with x facing forward from sensor
            float yw = (*it2).y; // world position in m with y facing left from sensor
            xwmin = xwmin<xw ? xwmin : xw;
            ywmin = ywmin<yw ? ywmin : yw;
            ywmax = ywmax>yw ? ywmax : yw;

            // top-view coordinates
            int y = (-xw * imageSize.height / worldSize.height) + imageSize.height;
            int x = (-yw * imageSize.width / worldSize.width) + imageSize.width / 2;

            // find enclosing rectangle
            top = top<y ? top : y;
            left = left<x ? left : x;
            bottom = bottom>y ? bottom : y;
            right = right>x ? right : x;

            // draw individual point
            cv::circle(topviewImg, cv::Point(x, y), 4, currColor, -1);
        }

        // draw enclosing rectangle
        cv::rectangle(topviewImg, cv::Point(left, top), cv::Point(right, bottom),cv::Scalar(0,0,0), 2);

        // augment object with some key data
        char str1[200], str2[200];
        sprintf(str1, "id=%d, #pts=%d", it1->boxID, (int)it1->lidarPoints.size());
        putText(topviewImg, str1, cv::Point2f(left-250, bottom+50), cv::FONT_ITALIC, 2, currColor);
        sprintf(str2, "xmin=%2.2f m, yw=%2.2f m", xwmin, ywmax-ywmin);
        putText(topviewImg, str2, cv::Point2f(left-250, bottom+125), cv::FONT_ITALIC, 2, currColor);  
    }

    // plot distance markers
    float lineSpacing = 2.0; // gap between distance markers
    int nMarkers = floor(worldSize.height / lineSpacing);
    for (size_t i = 0; i < nMarkers; ++i)
    {
        int y = (-(i * lineSpacing) * imageSize.height / worldSize.height) + imageSize.height;
        cv::line(topviewImg, cv::Point(0, y), cv::Point(imageSize.width, y), cv::Scalar(255, 0, 0));
    }

    // display image
    string windowName = "3D Objects";
    cv::namedWindow(windowName, cv::WINDOW_NORMAL);
    cv::imshow(windowName, topviewImg);

    if(bWait)
    {
        cv::waitKey(0); // wait for key to be pressed
    }
}

void filterKeypointWithBB(BoundingBox &boundingBox, std::vector<cv::KeyPoint> &kpts)
{
    for(auto it= kpts.begin(); it != kpts.end(); ++it)
    {
        // if((it->pt.x>boundingBox.roi.x) && (it->pt.x<(boundingBox.roi.x+boundingBox.roi.width)) \
        //     && (it->pt.y<boundingBox.roi.y) && (it->pt.y>(boundingBox.roi.y-boundingBox.roi.height)))
        if(boundingBox.roi.contains(it->pt))
        {
             boundingBox.keypoints.push_back(*it);   
        }
    }
}

bool operator==(cv::Point2f& p1, const cv::Point2f& p2)
{
    return p1.x == p2.x && p1.y == p2.y;   
}

double distance(cv::Point2f &p1, cv::Point2f &p2)
{
    cv::Point2f diff = p1-p2;
    return cv::sqrt(diff.x*diff.x + diff.y*diff.y);
}
// associate a given bounding box with the keypoints it contains
void clusterKptMatchesWithROI(BoundingBox &boundingBox, std::vector<cv::KeyPoint> &kptsPrev, std::vector<cv::KeyPoint> &kptsCurr, std::vector<cv::DMatch> &kptMatches)
{
    double distanceSum = 0.0;
    filterKeypointWithBB(boundingBox, kptsCurr);
    for(auto it = kptMatches.begin(); it != kptMatches.end(); ++it)
    {
        int id_1 = it->queryIdx, id_2 = it->trainIdx;
        if(boundingBox.roi.contains(kptsCurr[id_2].pt))
        {
            boundingBox.kptMatches.push_back(*it);
            distanceSum += distance(kptsPrev[id_1].pt, kptsCurr[id_2].pt);
        }
    }
    double distanceAvg = distanceSum/boundingBox.kptMatches.size();
    for(auto it = boundingBox.kptMatches.begin(); it != boundingBox.kptMatches.end(); )
    {
        int id_1 = it->queryIdx, id_2 = it->trainIdx;
        if((distance(kptsPrev[id_1].pt, kptsCurr[id_2].pt)-distanceAvg)>1)
        {
            it = boundingBox.kptMatches.erase(it);
        }
        else
        {
            it++;
        }
    }
}


// Compute time-to-collision (TTC) based on keypoint correspondences in successive images
void computeTTCCamera(std::vector<cv::KeyPoint> &kptsPrev, std::vector<cv::KeyPoint> &kptsCurr, 
                      std::vector<cv::DMatch> kptMatches, double frameRate, double &TTC, cv::Mat *visImg)
{
    vector<double> distRatios;
    for (auto it1 = kptMatches.begin(); it1 != kptMatches.end() - 1; ++it1)
    { 
        cv::KeyPoint kpOuterCurr = kptsCurr.at(it1->trainIdx);
        cv::KeyPoint kpOuterPrev = kptsPrev.at(it1->queryIdx);

        for (auto it2 = kptMatches.begin() + 1; it2 != kptMatches.end(); ++it2)
        { 
            double minDist = 100.0; 
            cv::KeyPoint kpInnerCurr = kptsCurr.at(it2->trainIdx);
            cv::KeyPoint kpInnerPrev = kptsPrev.at(it2->queryIdx);
            double distCurr = cv::norm(kpOuterCurr.pt - kpInnerCurr.pt);
            double distPrev = cv::norm(kpOuterPrev.pt - kpInnerPrev.pt);

            if (distPrev > std::numeric_limits<double>::epsilon() && distCurr >= minDist)
            { 

                double distRatio = distCurr / distPrev;
                distRatios.push_back(distRatio);
            }
        } 
    }     

    if (distRatios.size() == 0)
    {
        TTC = NAN;
        return;
    }

    double meanDistRatio = std::accumulate(distRatios.begin(), distRatios.end(), 0.0) / distRatios.size();

    double dT = 1 / frameRate;
    TTC = -dT / (1 - meanDistRatio);
}

void getMin(std::vector<LidarPoint> lidarPoints, double &minX)
{
    std::vector<double> xVec;
    double xAvg = 0.0;
    for(auto it= lidarPoints.begin(); it!=lidarPoints.end(); it++)
    {
        xVec.push_back(it->x);
    }
    sort(xVec.begin(), xVec.end());
    xAvg = std::accumulate(xVec.begin(), xVec.end(), 0.0)/xVec.size();
    int index = 0;
    while(index < xVec.size())
    {
        minX = xVec[index];
        if(abs(minX-xAvg)<1)
            break;
        index++;
    };
}

void computeTTCLidar(std::vector<LidarPoint> &lidarPointsPrev,
                     std::vector<LidarPoint> &lidarPointsCurr, double frameRate, double &TTC)
{
    double minXPrev = 2.0, minXCurr = 2.0;
    double minX = 2.0, maxX = 20.0;

    // std::cout<<xPrev.size()<<": "<<xCurr.size()<<std::endl;
    //avoid outliers
    getMin(lidarPointsPrev, minXPrev);
    getMin(lidarPointsCurr, minXCurr);
    if(minXCurr >= minXPrev || minXCurr >= maxX || minXPrev >= maxX)
    {
        TTC = NAN;
    }
    else{
        TTC = minXCurr/((minXPrev-minXCurr)*frameRate);
    }
}

bool operator==(const LidarPoint& p1, const LidarPoint& p2)
{
    return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;   
}

void matchBoundingBoxes(std::vector<cv::DMatch> &matches, std::map<int, int> &bbBestMatches, DataFrame &prevFrame, DataFrame &currFrame)
{
    int numOfKptMax = 0, numOfKpt = 0;
    int boxIDPrev = -1;
    if(matches.size() == 0)
        return;
    for(auto it_curr = currFrame.boundingBoxes.begin(); it_curr != currFrame.boundingBoxes.end(); ++it_curr)
    {
        for(auto it_pre = prevFrame.boundingBoxes.begin(); it_pre != prevFrame.boundingBoxes.end(); ++it_pre)
        {
            for(auto it = matches.begin(); it != matches.end(); ++it)
            {
                int id_1 = it->queryIdx, id_2 = it->trainIdx;
                if(((std::find((*it_pre).lidarPoints.begin(), (*it_pre).lidarPoints.end(), prevFrame.lidarPoints[id_1])) != (*it_pre).lidarPoints.end())
                && ((std::find((*it_curr).lidarPoints.begin(), (*it_curr).lidarPoints.end(), currFrame.lidarPoints[id_2])) != (*it_curr).lidarPoints.end()))
                {
                    numOfKpt++;        
                }
            }
            if(numOfKpt>numOfKptMax)
            {
                numOfKptMax = numOfKpt;
                boxIDPrev = (*it_pre).boxID;
            }
            numOfKpt = 0;
        }
        numOfKptMax = 0;
        if(boxIDPrev != -1)
        {
            // std::cout<<(*it_curr).boxID<<": "<<boxIDPrev<<std::endl;
            bbBestMatches.insert({boxIDPrev, (*it_curr).boxID});
            boxIDPrev = -1;
        }
    }
}
