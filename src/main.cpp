#include <bits/stringfwd.h>
#include <opencv2/core/mat.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "SimplePF.h"

using namespace cv;
using namespace std;

cv::Mat frame;	//current frame
cv::Mat gray_frame;	//current frame
cv::Mat out;	//PF outpute

int nParticles = 100;
int nIters = 10;

int keyboard;

int main(int argc, char** argv)
{
    cout << "start" << endl;

    namedWindow("Tracking");

    // create the capture object
    char* videoFilename = "/home/neko/Desktop/Surveillance/testVideo.mp4";
    VideoCapture capture(videoFilename);

    if (!capture.isOpened()){
        cerr << "Unable to open video file: " << endl;
        exit(EXIT_FAILURE);
    }

    // Create Particle Filter
    SimplePF *PF = new SimplePF(&frame, nParticles, nIters);
    PF->setParticleWidth(55);

    while (true){
        if (capture.read(frame)){
            cvtColor(frame, gray_frame, CV_BGR2GRAY);
            PF->setIMG(&gray_frame);
            PF->run();
            out = PF->getIMG();
            imshow("Tracking", out);
        }

        keyboard = cvWaitKey(30); // wait 10 ms or for key stroke
        if (keyboard == 27)
            break; // if ESC, break and quit
    }

    cout << "finish" << endl;
    return 0;
}