#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

using namespace std;

void cornernessHarris()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("images/img1.png");
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY); // convert to grayscale

    // Detector parameters
    int blockSize = 2;     // for every pixel, a blockSize × blockSize neighborhood is considered
    int apertureSize = 3;  // aperture parameter for Sobel operator (must be odd)
    int minResponse = 100; // minimum value for a corner in the 8bit scaled response matrix
    double k = 0.04;       // Harris parameter (see equation for details)

    // Detect Harris corners and normalize output
    cv::Mat dst, dst_norm, dst_norm_scaled;
    dst = cv::Mat::zeros(img.size(), CV_32FC1);
    cv::cornerHarris(img, dst, blockSize, apertureSize, k, cv::BORDER_DEFAULT);
    cv::normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
    cv::convertScaleAbs(dst_norm, dst_norm_scaled);


    // TODO: Your task is to locate local maxima in the Harris response matrix 
    // and perform a non-maximum suppression (NMS) in a local neighborhood around 
    // each maximum. The resulting coordinates shall be stored in a list of keypoints 
    // of the type `vector<cv::KeyPoint>`.
    cv::Mat dst_norm_scaled_pad;
    int pad_size = apertureSize/2;
    cv::copyMakeBorder(dst_norm_scaled, dst_norm_scaled_pad, pad_size, pad_size, pad_size, pad_size, cv::BORDER_CONSTANT, cv::Scalar(0));
    vector<cv::KeyPoint> corners;
    for(int row=0; row<dst_norm_scaled.rows; row++)
    {
        for( int col=0; col<dst_norm_scaled.cols; col++)
        {
            int row_max = pad_size;
            int col_max = pad_size;
            cv::KeyPoint kp;
            for(int row_win=row; row_win<=row+apertureSize; row_win++)
            {
                for(int col_win=col; col_win<=col+apertureSize; col_win++)
                {
                    if( dst_norm_scaled_pad.at<uchar>(row_win, col_win)>dst_norm_scaled_pad.at<uchar>(row_max, col_max))
                    {
                        row_max=row_win;
                        col_max=col_win;
                    }
                }
            }
            kp.pt = dst_norm_scaled_pad.at<cv::Point2f>(row_max-pad_size, col_max-pad_size);
            corners.push_back(kp);
        }
    }


    // visualize results
    string windowName = "Harris Corner Detector Response Matrix";
    cv::namedWindow(windowName, 4);
    cv::Mat dst_norm_scaled_w_corners;
    cv::drawKeypoints(dst_norm_scaled, corners, dst_norm_scaled_w_corners, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cv::imshow(windowName, dst_norm_scaled_w_corners);
    cv::waitKey(0);


}

int main()
{
    cornernessHarris();
}