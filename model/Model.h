//
// Created by px on 7/8/2019.
//

#ifndef MODEL_H
#define MODEL_H


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

