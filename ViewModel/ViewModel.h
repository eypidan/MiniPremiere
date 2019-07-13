#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "../model/Model.h"
#include "./commands/OpenFileCommand.h"
#include "../common/Notification.h"
class ViewModel {
private:
	std::shared_ptr<QImage>q_image;
	std::shared_ptr<Model> model;

	std::shared_ptr<OpenFileCommand> opFileCommand;
    std::shared_ptr<FetchQimageCommand> fQimageCommand;
	std::shared_ptr<Notification> UpdateViewNotification;
public:
	ViewModel();
	inline void Bind(std::shared_ptr<Model> &newmodel){
	    this->model = newmodel;
	}

	//command openfile
	inline std::shared_ptr<CommandBase> GetOpenFileCommand(){
        return std::dynamic_pointer_cast<CommandBase>(opFileCommand);
    }
    inline void ExecOpenFileCommand(std::string &path){
		opFileCommand->exec();
	}

    //command FetcgQimage
    inline std::shared_ptr<CommandBase> GetFetchQimageCommand(){
        return std::dynamic_pointer_cast<CommandBase>(fQimageCommand);
    }
    void ExecFetchQimageCommand(std::string path);

	inline void SetUpdateViewNotification(std::shared_ptr<Notification> notification);
};

ViewModel::ViewModel(){
	opFileCommand = std::make_shared<OpenFileCommand>();
	fQimageCommand = std::make_shared<FetchQimageCommand>();
}

#endif





