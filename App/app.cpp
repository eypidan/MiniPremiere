#include "app.h"

App::App()
{
    mainwindow = std::make_shared<MainWindow>();
    viewmodel = std::make_shared<ViewModel>();
    model = std::make_shared<Model>();

    viewmodel->Bind(model);

    mainwindow->SetQImage(viewmodel->GetQImage());
    mainwindow->SetFrameRate(viewmodel->GetVideoFps());
    mainwindow->SetTimeDuration(viewmodel->GetVideoDuration());

    mainwindow->SetFetchQImageCommand(viewmodel->GetFetchQimageCommand());
    mainwindow->SetOpenFileCommand(viewmodel->GetOpenFileCommand());
    mainwindow->SetTimeJumpCommand(viewmodel->GetRefreshTimeStampCommand());

    viewmodel->SetUpdateViewNotification(mainwindow->GetUpdateViewNotification());
    viewmodel->SetUpdateTimeStampNotification(mainwindow->GetUpdateTimeStampNotification());
}
void App::run()
{
    mainwindow->show();
}
