#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include "VideoStreamClient.hpp"

int main(int argc, char** argv) {

    VideoStreamClient::instance().subscribe("tcp://192.168.0.107:5560");
    int key = 255;
//    while(true) {
//        cv::imshow("frame", VideoStreamClient::instance().getFrame());
//        cv::waitKey(1);
//
//    }

    return 0;
}