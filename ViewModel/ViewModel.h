#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <../model/Model.h>
#include "./commands/OpenFileCommand.h"
#include "../common/Notification.h"
class ViewModel {
private:
	std::shared_ptr<QImage>q_image;
	std::shared_ptr<Model> model;

	std::shared_ptr<CommandBase> OpenFileCommand;

	std::shared_ptr<Notification> UpdateViewNotification;
public:
	ViewModel() = default;
	void ExecOpenFileCommand(std::string path);
	std::shared_ptr<CommandBase> GetOpenFileCommand();

	void SetUpdateViewNotification(std::shared_ptr<Notification> notification);
};


#endif





