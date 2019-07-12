#ifndef ViewModel_H
#define ViewModel_H
#include <include/View.h>
#include <include/Model.h>
extern view api;

class ViewModel
{
    private: 
	std::shared_ptr<View> view;
	std::shared_ptr<Model> model;

	//std::shared_ptr<Command> open_file_command;
	//std::shared_ptr<Command> delete_part_command;
	//std::shared_ptr<Command> add_parts_command;
	//std::shared_ptr<Command> save_file_command;
	
	//std::shared_ptr<Command>
	//std::shared_ptr<Command>
	//std::shared_ptr<Command>

    public:	
	ViewModel();
	string exec_open_file_command(std::string filepath);  
	shared_ptr<Model> delete_part_command(std:://parameter according to view, catens of two time points);
	shared_ptr<Model> add_part_command(std:: string vew_filepath1, std::string view_filepath2); //the product should be 1 + 2 but not 2 + 1;
	shared_ptr<Model> save_command(std::(std::string view_newfilepath, std::string view_oldfilepath);//should figure out whether the file should be rewrite;
	shared_ptr<Model> open_command(std::string filepath);	
	shared_ptr<Model> reverse_command(std::string filepath);
}

#endif





