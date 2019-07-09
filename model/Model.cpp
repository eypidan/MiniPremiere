//
// Created by px on 7/8/2019.
//
#include "Model.h"
//
//Mat RotateImage(Mat src, double angle) {
//    Mat dst;
//    try {
//        //float scale = 200.0/ src.rows;//缩放因子
//        //resize(src, src, Size(), scale, scale, INTER_LINEAR);
//        //输出图像的尺寸与原图一样
//        Size dst_sz(src.cols, src.rows);
//
//        //指定旋转中心
//        Point2f center(static_cast<float>(src.cols / 2.), static_cast<float>(src.rows / 2.));
//
//        //获取旋转矩阵（2x3矩阵）
//        Mat rot_mat = getRotationMatrix2D(center, angle, 1.0);
//        //设置选择背景边界颜色
//        Scalar borderColor = Scalar(0, 0, 0);
//        warpAffine(src, dst, rot_mat, src.size(), INTER_LINEAR, BORDER_CONSTANT, borderColor);
//        //复制边缘填充
//    }
//    catch (Exception e) {
//    }
//    return dst;
//}
//
//int main(){
//    //TODO provide video store api
//    VideoCapture capture;
//    Mat frame,newFrame;
//    frame = capture.open("C:\\Users\\px\\Desktop\\MiniPremiere\\test.mp4");
//    if(!capture.isOpened()) {
//        printf("can not open ...\n");
//        return -1;
//    }
//    namedWindow("output", WINDOW_NORMAL);
//
//    while (capture.read(frame)){
//        newFrame = RotateImage(frame,-90);
//        imshow("output", newFrame);
//        waitKey(10);
//    }
//    capture.release();
//    return 0;
//
//}