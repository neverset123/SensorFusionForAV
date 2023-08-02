#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>


using namespace std;

void createMatrix1()
{
    // create matrix
    int nrows = 480, ncols = 640;
    cv::Mat m3_8u;
    m3_8u.create(nrows, ncols, CV_8UC3);
    m3_8u.reshape(1, m3_8u.rows*m3_8u.cols).col(0).setTo(cv::Scalar(255));

    // show result
    string windowName = "First steps in OpenCV (m3_8u)";
    cv::namedWindow(windowName, 1); // create window
    cv::imshow(windowName, m3_8u);
    cv::waitKey(0); // wait for keyboard input before continuing

    // STUDENT TASK :
    // Display the results from the STUDENT TASK above

}


int main()
{
    createMatrix1();
    return 0;
}