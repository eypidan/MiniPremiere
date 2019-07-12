#include "../app.h"

APP::APP():view(new View), model(new Model), viewmodel(new ViewModel)
{
    viewmodel->bind(model);			//get view and viewmodel mix
    view->setframe(viewmodel->getframe());	//send the frame at this time from viewmodel to view;
    view->set_open_file_command(viewmodel->get_open_file_command());
    view->set_start_command(viewmodel->get_start_command());
    view->set_stop_command(viewmodel->get_stop_command());
    viewmodel->set_update_view_notification(view->get_update_view_notification());
    model->set_update_display_data_notification(viewmodel->get_update_display_data_notification);
}
void App::run()
{
    view->show():
}
