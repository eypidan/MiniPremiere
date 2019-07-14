#include "./Model.h"

std::shared_ptr<EditableVideo> Model::openFile(const std::string path) {
    if(currentVideo == nullptr)
        currentVideo = std::make_shared<EditableVideo>(path);
    else{
        std::shared_ptr<EditableVideo> middle = std::make_shared<EditableVideo>(path);
        currentVideo = middle;
        middle = nullptr;
    }
    return currentVideo;
}