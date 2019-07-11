//
// Created by px on 7/9/2019.
//
#include "./model/Model.h"

int main(){
   EditableVideo test("C:\\Users\\px\\Desktop\\MiniPremiere\\test.mp4");
   cv::Mat image;
   for(int i=0;i<50;i++){
      image = test.getNextImage();
       cv::namedWindow("Video", CV_WINDOW_AUTOSIZE);
       cv::imshow("Video", image);
       cv::waitKey(20);
   }
}
