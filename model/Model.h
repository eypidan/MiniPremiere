//
// Created by px on 7/8/2019.
//

#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include <iostream>
#include <memory>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include "./EditableVideo.h"
class Model
{
private:
    cv::Mat image;
    //std::shared_ptr<Notification> update_display_data_notification;
public:
    Model()= default;
    //void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    void open_file(std::string path);
    cv::Mat& get();
    cv::Mat& getOrigin();
    void notify();
    void save_file(std::string path);
    void save_bmp_file(std::string path);

    void alterBrightAndContrast(int nbright, int nContrast);
    void detect_face();
    void filterReminiscence(); //Filter No.1
    void reset();
    void rotate(double angle);
    void crop(int x1, int y1, int x2, int y2);
};

#endif //MODEL_MODEL_H
