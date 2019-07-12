#ifndef APP_H
#define APP_H

#include "../model/Model.h"
#include "../View/MainWindow.h"
#include "../View/View.cpp"
#include "../ViewModel/ViewModel.h"

class APP
{
    private:
	std::shard_ptr<View> view;
	std::shard_ptr<Model> model;
	std::shard_ptr<ViewModel> viewmodel;
    public:
	APP();
	void run();
}
#endif
