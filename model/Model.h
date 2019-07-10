//
// Created by px on 7/8/2019.
//

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <memory>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
extern "C"{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavutil/opt.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/channel_layout.h>
    #include <libavutil/common.h>
    #include <libavutil/imgutils.h>
    #include <libavutil/mathematics.h>
    #include <libavutil/samplefmt.h>
}
#include "./EditableVideo.h"

class Model
{
private:
    EditableVideo *instance_video = nullptr;
public:
    Model()= default;
    // void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    EditableVideo &open_file(std::string path);
//    cv::Mat& get();
//    cv::Mat& getOrigin();
//    void notify();
//    void save_file(std::string path);
//    void save_bmp_file(std::string path);
//
//    void alterBrightAndContrast(int nbright, int nContrast);
//    void detect_face();
//    void filterReminiscence(); //Filter No.1
//    void reset();
//    void rotate(double angle);
//    void crop(int x1, int y1, int x2, int y2);
};

EditableVideo& Model::open_file(std::string path) {
    //EditableVideo current(path);
    //return &this->instance_video;
}
#endif //MODEL_H

