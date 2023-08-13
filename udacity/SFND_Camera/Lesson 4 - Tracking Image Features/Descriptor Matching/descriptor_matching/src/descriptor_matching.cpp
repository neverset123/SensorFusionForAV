#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

#include "structIO.hpp"

using namespace std;

void matchDescriptors(cv::Mat &imgSource, cv::Mat &imgRef, vector<cv::KeyPoint> &kPtsSource, vector<cv::KeyPoint> &kPtsRef, cv::Mat &descSource, cv::Mat &descRef,
                      vector<cv::DMatch> &matches, string descriptorType, string matcherType, string selectorType)
{

    // configure matcher
    bool crossCheck = false;
    cv::Ptr<cv::DescriptorMatcher> matcher;

    if (matcherType.compare("MAT_BF") == 0)
    {

        int normType = descriptorType.compare("DES_BINARY") == 0 ? cv::NORM_HAMMING : cv::NORM_L2;
        matcher = cv::BFMatcher::create(normType, crossCheck);
        cout << "BF matching cross-check=" << crossCheck;
    }
    else if (matcherType.compare("MAT_FLANN") == 0)
    {
        if (descSource.type() != CV_32F)
        { // OpenCV bug workaround : convert binary descriptors to floating point due to a bug in current OpenCV implementation
            descSource.convertTo(descSource, CV_32F);
            descRef.convertTo(descRef, CV_32F);
        }

        // TODO : implement FLANN matching
        cout << "FLANN matching";
        matcher = cv::FlannBasedMatcher::create();
    }

    // perform matching task
    if (selectorType.compare("SEL_NN") == 0)
    { // nearest neighbor (best match)

        double t = (double)cv::getTickCount();
        matcher->match(descSource, descRef, matches); // Finds the best match for each descriptor in desc1
        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        cout << " (NN) with n=" << matches.size() << " matches in " << 1000 * t / 1.0 << " ms" << endl;
    }
    else if (selectorType.compare("SEL_KNN") == 0)
    { // k nearest neighbors (k=2)

        // TODO : implement k-nearest-neighbor matching
        vector<vector<cv::DMatch>> knnmatches;
        double t = (double)cv::getTickCount();
        matcher->knnMatch(descSource, descRef, knnmatches, 2);
        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        // TODO : filter matches using descriptor distance ratio test
        float ratio = 0.8;
        for(int i=0; i<knnmatches.size(); i++)
        {
            if(knnmatches[i][0].distance/knnmatches[i][1].distance<ratio)
            {
                matches.push_back(knnmatches[i][0]);
            }
        }

        cout << " (KNN) with n=" << matches.size() << " matches in " << 1000 * t / 1.0 << " ms" << endl;
        cout << "percentage of discarded matches: "<< (knnmatches.size()-matches.size())/(float) knnmatches.size()<< endl;
    }

    // visualize results
    cv::Mat matchImg = imgRef.clone();
    cv::drawMatches(imgSource, kPtsSource, imgRef, kPtsRef, matches,
                    matchImg, cv::Scalar::all(-1), cv::Scalar::all(-1), vector<char>(), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    string windowName = "Matching keypoints between two camera images (best 50)";
    cv::namedWindow(windowName, 7);
    cv::imshow(windowName, matchImg);
    cv::waitKey(0);
}

int main()
{
    cv::Mat imgSource = cv::imread("images/img1gray.png");
    cv::Mat imgRef = cv::imread("images/img2gray.png");

    vector<cv::KeyPoint> kptsSourceBriskLarge, kptsRefBriskLarge, kptsSourceBriskSmall, kptsRefBriskSmall, kptsSourceSift, kptsRefSift; 
    readKeypoints("dat/C35A5_KptsSource_BRISK_large.dat", kptsSourceBriskLarge);
    readKeypoints("dat/C35A5_KptsRef_BRISK_large.dat", kptsRefBriskLarge);
    readKeypoints("dat/C35A5_KptsSource_BRISK_small.dat", kptsSourceBriskSmall);
    readKeypoints("dat/C35A5_KptsRef_BRISK_small.dat", kptsRefBriskSmall);   
    readKeypoints("dat/C35A5_KptsSource_SIFT.dat", kptsSourceSift);
    readKeypoints("dat/C35A5_KptsRef_SIFT.dat", kptsRefSift);

    cv::Mat descSourceBriskLarge, descRefBriskLarge, descSourceBriskSmall, descRefBriskSmall, descSourceBSift, descRefSift; 
    readDescriptors("dat/C35A5_DescSource_BRISK_large.dat", descSourceBriskLarge);
    readDescriptors("dat/C35A5_DescRef_BRISK_large.dat", descRefBriskLarge);
    readDescriptors("dat/C35A5_DescSource_BRISK_small.dat", descSourceBriskSmall);
    readDescriptors("dat/C35A5_DescRef_BRISK_small.dat", descRefBriskSmall);
    readDescriptors("dat/C35A5_DescSource_SIFT.dat", descSourceBSift);
    readDescriptors("dat/C35A5_DescRef_SIFT.dat", descRefSift);

    vector<cv::DMatch> matchesBriskLarge, matchesBriskSmall, matchesSift;
    // string matcherType = "MAT_BF"; 
    // string matcherType = "MAT_FLANN"; 
    // string descriptorType = "DES_BINARY";
    // string descriptorType = "DES_GRADIENT";
    // string selectorType = "SEL_NN"; 
    // string selectorType = "SEL_KNN";
    matchDescriptors(imgSource, imgRef, kptsSourceBriskSmall, 
                    kptsRefBriskSmall, descSourceBriskSmall, descRefBriskSmall, matchesBriskSmall, 
                    "DES_BINARY", "MAT_BF", "SEL_NN");
    matchesBriskSmall.clear();
    matchDescriptors(imgSource, imgRef, kptsSourceBriskSmall, 
                    kptsRefBriskSmall, descSourceBriskSmall, descRefBriskSmall, matchesBriskSmall, 
                    "DES_BINARY", "MAT_BF", "SEL_KNN");
    
    matchDescriptors(imgSource, imgRef, kptsSourceBriskLarge, 
                    kptsRefBriskLarge, descSourceBriskLarge, descRefBriskLarge, matchesBriskLarge, 
                    "DES_BINARY", "MAT_BF", "SEL_KNN");
    matchesBriskLarge.clear();
    matchDescriptors(imgSource, imgRef, kptsSourceBriskLarge, 
                kptsRefBriskLarge, descSourceBriskLarge, descRefBriskLarge, matchesBriskLarge, 
                "DES_BINARY", "MAT_FLANN", "SEL_KNN");
    matchDescriptors(imgSource, imgRef, kptsSourceSift, 
                kptsRefSift, descSourceBSift, descRefSift, matchesSift, 
                "DES_GRADIENT", "MAT_BF", "SEL_KNN");
    matchesSift.clear();
    matchDescriptors(imgSource, imgRef, kptsSourceSift, 
                kptsRefSift, descSourceBSift, descRefSift, matchesSift, 
                "DES_GRADIENT", "MAT_FLANN", "SEL_KNN");
}