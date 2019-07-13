#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <memory>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTextStream>
#include <QPalette>
#include <QStatusBar>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLineEdit>
#include "../common/command.h"
#include "./Notification/UpdateViewNotification.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Initialize the view
    MainWindow();
    void CreateMenuAndToolBar();
    void CreateStatusBar();
    void CreatePicLabel();
    void CreatePlayButton();
    void SetTimer();
    void SetSlider();
    void SetLayer();

    void UpdateQImage();
    //set command
    void SetOpenFileCommand(std::shared_ptr<commandBase>);
    void SetGetFrameRateCommand(std::shared_ptr<commandBase>);
    void SetFetchQimageCommand(std::shared_ptr<commandBase>);
    //set data
    void SetQImage(std::shared_ptr<QImage>);
    void SetFrameRate(std::shared_ptr<int>);

    //get notification
    std::shared_ptr<Notification> GetUpdateViewNotification();

private slots:
    void OnClick();
    void OnTimer();
    void SetLineEditValue();
    void OpenOperation();
    void SaveOperation();
    void SaveAsOperation();
    void ExitOperation();
    void HelpOperation();
    void AboutUsOperation();
    //QImage FromCVtoQImage(const cv::Mat &mat);

private:
    QPushButton *button;
    QLabel *pic;
    QSlider *slider;
    QLineEdit *start;
    QLineEdit *end;
    QTimer *timer;
    QPixmap picture;

    std::shared_ptr<QImage> image;
    std::shared_ptr<int> framerate;
    std::shared_ptr<commandBase> OpenFileCommand;
    std::shared_ptr<commandBase> GetFrameRateCommand;
    std::shared_ptr<commandBase> FetchQimageCommand;
    std::shared_ptr<UpdateViewNotification> TheUpdateViewNotification;
};
#endif
