#ifndef VIEWMODEL_H
<<<<<<< HEAD
#define VIEWMODEL_H 
//#include <./view/mainwindow.h>
#include <./model/Model.h>
#define framerate = 24;
class ViewModel 
{
    private:
	std::shared_ptr<EditableVideo> Video;
    public:
	ViewModel()= default;
	~ViewModel(){Video.reset();}
	std::shared_ptr<EditableVideo> initvideo(const std::string path);
	std::shared_ptr<cv::Mat> openfile(const std::string path, int nowtime = 0);
//	std::shared_ptr<cv::Mat> 
}

std::shared_ptr<EditableVideo> initvideo(const std::string path)
{
    Model model;
    Video = model.openfile(path);
}

std::shared_ptr<cv::Mat> openfile(const std::string path, int nowtime = 0)
{
    int nowframes = nowtime * framerate;
    std::shared_ptr<cv::Mat> currentmat;
    initvideo(path);
    for (int i = 0; i <= nowframes; i++)
    {
	currentmat = Video->getNextImage();
	cv::waitKey(24);
    }

    return currentmat;
}
=======
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


>>>>>>> Model

#endif
