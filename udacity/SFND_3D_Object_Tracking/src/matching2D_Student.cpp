#include <numeric>
#include "matching2D.hpp"

using namespace std;

// Find best matches for keypoints in two camera images based on several matching methods
void matchDescriptors(std::vector<cv::KeyPoint> &kPtsSource, std::vector<cv::KeyPoint> &kPtsRef, cv::Mat &descSource, cv::Mat &descRef,
                      std::vector<cv::DMatch> &matches, std::string matcherType, std::string selectorType, string descriptorType)
{
    // configure matcher
    bool crossCheck = false;
    cv::Ptr<cv::DescriptorMatcher> matcher;

    if (matcherType.compare("MAT_BF") == 0)
    {
        int normType = descriptorType.compare("SIFT") == 0 ? cv::NORM_L2:cv::NORM_HAMMING;
        matcher = cv::BFMatcher::create(normType, crossCheck);
    }
    else if (matcherType.compare("MAT_FLANN") == 0)
    {
        if (descSource.type() != CV_32F)
        { 
            descSource.convertTo(descSource, CV_32F);
            descRef.convertTo(descRef, CV_32F);
        }
        matcher = cv::FlannBasedMatcher::create();
    }

    // perform matching task
    if (selectorType.compare("SEL_NN") == 0)
    { // nearest neighbor (best match)

        matcher->match(descSource, descRef, matches); // Finds the best match for each descriptor in desc1
    }
    else if (selectorType.compare("SEL_KNN") == 0)
    { // k nearest neighbors (k=2)
        vector<vector<cv::DMatch>> knnmatches;
        double t = (double)cv::getTickCount();
        matcher->knnMatch(descSource, descRef, knnmatches, 2);
        float ratio = 0.8;
        for(int i=0; i<knnmatches.size(); i++)
        {
            if(knnmatches[i][0].distance/knnmatches[i][1].distance<ratio)
            {
                matches.push_back(knnmatches[i][0]);
            }
        }

    }
}

// Use one of several types of state-of-art descriptors to uniquely identify keypoints
void descKeypoints(vector<cv::KeyPoint> &keypoints, cv::Mat &img, cv::Mat &descriptors, string descriptorType)
{
    // select appropriate descriptor
    cv::Ptr<cv::DescriptorExtractor> extractor;
    if (descriptorType.compare("BRISK") == 0)
    {
        int threshold = 30;        // FAST/AGAST detection threshold score.
        int octaves = 3;           // detection octaves (use 0 to do single scale)
        float patternScale = 1.0f; // apply this scale to the pattern used for sampling the neighbourhood of a keypoint.

        extractor = cv::BRISK::create(threshold, octaves, patternScale);
    }
    else if (descriptorType.compare("BRIEF") == 0)
    {
        extractor = cv::xfeatures2d::BriefDescriptorExtractor::create();
    }
    else if (descriptorType.compare("ORB") == 0)
    {
        extractor = cv::ORB::create();
    }
    else if (descriptorType.compare("FREAK") == 0)
    {
        extractor = cv::xfeatures2d::FREAK::create();
    }
    else if (descriptorType.compare("AKAZE") == 0)
    {
        extractor = cv::AKAZE::create();
    }
    else if (descriptorType.compare("SIFT") == 0)
    {
        extractor = cv::SIFT::create();
    }
    else
    {
        std::cout<<"descriptor type is not defined!";
        return;
    }

    // perform feature description
    double t = (double)cv::getTickCount();
    
    extractor->compute(img, keypoints, descriptors);
    t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
    // cout << descriptorType << " descriptor extraction in " << 1000 * t / 1.0 << " ms" << endl;
}

void viz(cv::Mat &img, vector<cv::KeyPoint> kpts, string detectorName, bool bVis=false)
{
    if (bVis)
    {
        cv::Mat visImage = img.clone();
        cv::drawKeypoints(img, kpts, visImage, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
        string windowName = detectorName+" Corner Detector Results";
        cv::namedWindow(windowName, 6);
        imshow(windowName, visImage);
        cv::waitKey(0);
    }
}

void detKeypointsSift(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    // ORB detector / descriptor
    cv::Ptr<cv::FeatureDetector> detector = cv::SIFT::create();
    detector->detect(img, keypoints);
}

void detKeypointsAkaze(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    cv::Ptr<cv::FeatureDetector> detector = cv::AKAZE::create();
    detector->detect(img, keypoints);
}

void detKeypointsOrb(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    // ORB detector / descriptor
    cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();
    detector->detect(img, keypoints);
}

void detKeypointsBrisk(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    int threshold = 30;
    cv::Ptr<cv::FeatureDetector> detector = cv::BRISK::create(threshold);
    detector->detect(img, keypoints);
}


void detKeypointsFast(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    int threshold = 30;
    cv::Ptr<cv::FeatureDetector> detector = cv::FastFeatureDetector::create(threshold);
    detector->detect(img, keypoints);
}

// 
void detKeypointsHarris(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    // compute detector parameters based on image size
    int blockSize = 4;       //  size of an average block for computing a derivative covariation matrix over each pixel neighborhood
    double maxOverlap = 0.0; // max. permissible overlap between two features in %
    double minDistance = (1.0 - maxOverlap) * blockSize;
    int maxCorners = img.rows * img.cols / max(1.0, minDistance); // max. num. of keypoints

    double qualityLevel = 0.01; // minimal accepted quality of image corners
    double k = 0.04;

    // Apply corner detection
    vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack(img, corners, maxCorners, qualityLevel, minDistance, cv::Mat(), blockSize, true, k);

    // add corners to result vector
    for (auto it = corners.begin(); it != corners.end(); ++it)
    {
        cv::KeyPoint newKeyPoint;
        newKeyPoint.pt = cv::Point2f((*it).x, (*it).y);
        newKeyPoint.size = blockSize;
        keypoints.push_back(newKeyPoint);
    }
}


// Detect keypoints in image using the traditional Shi-Thomasi detector
void detKeypointsShiTomasi(vector<cv::KeyPoint> &keypoints, cv::Mat &img)
{
    // compute detector parameters based on image size
    int blockSize = 4;       //  size of an average block for computing a derivative covariation matrix over each pixel neighborhood
    double maxOverlap = 0.0; // max. permissible overlap between two features in %
    double minDistance = (1.0 - maxOverlap) * blockSize;
    int maxCorners = img.rows * img.cols / max(1.0, minDistance); // max. num. of keypoints

    double qualityLevel = 0.01; // minimal accepted quality of image corners
    double k = 0.04;

    // Apply corner detection
    vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack(img, corners, maxCorners, qualityLevel, minDistance, cv::Mat(), blockSize, false, k);

    // add corners to result vector
    for (auto it = corners.begin(); it != corners.end(); ++it)
    {

        cv::KeyPoint newKeyPoint;
        newKeyPoint.pt = cv::Point2f((*it).x, (*it).y);
        newKeyPoint.size = blockSize;
        keypoints.push_back(newKeyPoint);
    }
}

void detKeypointsModern(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, std::string detectorType, bool bVis)
{
    if(detectorType.compare("SHITOMASI")==0)
    {
        detKeypointsShiTomasi(keypoints, img);
    }
    else if(detectorType.compare("HARRIS")==0)
    {
        detKeypointsHarris(keypoints, img);
    }
    else if(detectorType.compare("FAST")==0)
    {
        detKeypointsFast(keypoints, img);
    }
    else if(detectorType.compare("BRISK")==0)
    {
        detKeypointsBrisk(keypoints, img);
    }
    else if(detectorType.compare("ORB")==0)
    {
        detKeypointsOrb(keypoints, img);
    }
    else if(detectorType.compare("AKAZE")==0)
    {
        detKeypointsAkaze(keypoints, img);
    }
    else if(detectorType.compare("SIFT")==0)
    {
        detKeypointsSift(keypoints, img);
    }
    else{
        throw std::invalid_argument( "invalid detector type" );
    }

    // visualize results
    viz(img, keypoints, detectorType, bVis);
}