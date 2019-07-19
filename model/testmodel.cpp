//
// Created by px on 7/9/2019.
//
#include "./Model.h"

int main(){

    Model testModel;
    std::shared_ptr<EditableVideo> testVideo;
    testVideo = testModel.openFile("C:\\Users\\px\\Downloads\\erer.mp4");
    std::shared_ptr<cv::Mat> testMat;
    testVideo->seekImage(0);
    for(int i=0;i<20;i++){
        testMat = testVideo->getNextImage();
        cv::namedWindow("Video", CV_WINDOW_AUTOSIZE);
        cv::imshow("Video", *testMat);
        cv::waitKey(4);
    }
    testVideo = testModel.openFile("C:\\Users\\px\\Downloads\\lala.mp4");
    testVideo->seekImage(15);
    for(int i=0;i<300;i++){
        testMat = testVideo->getNextImage();
        cv::namedWindow("Video", CV_WINDOW_AUTOSIZE);
        cv::imshow("Video", *testMat);
        cv::waitKey(4);
    }
}
