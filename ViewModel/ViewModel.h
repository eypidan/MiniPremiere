#ifndef VIEWMODEL_H
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

#endif
