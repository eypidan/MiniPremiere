#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../model/Model.h"
#include "../common/Command.h"

#include "../common/Notification.h"
class ViewModel {
private:
	std::shared_ptr<QImage>q_image;
	std::shared_ptr<Model> model;
	std::shared_ptr<cv::Mat> cv_image;
	std::shared_ptr<EditableVideo> testVideo;
	std::shared_ptr<CommandBase> opFileCommand;
    std::shared_ptr<CommandBase> fQimageCommand;
	std::shared_ptr<Notification> UpdateViewNotification;
public:
	ViewModel();
	inline void Bind(std::shared_ptr<Model> &newmodel){
	    this->model = newmodel;
	}

	//command openfile
	inline std::shared_ptr<CommandBase> GetOpenFileCommand(){
        return std::static_pointer_cast<CommandBase>(opFileCommand);
    }
    inline void ExecOpenFileCommand(std::string &path){
		testVideo = model->openFile(path);
	}

    //command FetcgQimage
    inline std::shared_ptr<CommandBase> GetFetchQimageCommand(){
        return std::static_pointer_cast<CommandBase>(fQimageCommand);
    }
    inline void ExecFetchQimageCommand(){
		cv_image = testVideo->getNextImage();
	}

	//inline void SetUpdateViewNotification(std::shared_ptr<Notification> notification);
};



#endif





