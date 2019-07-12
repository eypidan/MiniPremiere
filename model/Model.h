//
// Created by px on 7/8/2019.
//

#ifndef MODEL_H
#define MODEL_H


#include "./EditableVideo.h"
class Model {
private:
    std::shared_ptr<EditableVideo> currentVideo;
public:
    Model()= default;
    ~Model(){currentVideo.reset();}
    std::shared_ptr<EditableVideo> openFile(const std::string path);
};

std::shared_ptr<EditableVideo> Model::openFile(const std::string path) {
    currentVideo = std::make_shared<EditableVideo>(path);
    return currentVideo;
}


#endif //MODEL_H

