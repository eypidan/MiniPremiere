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
    //set command
    //void SetOpenFileCommand(std::shared_ptr<Command>);

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
    //std::shared_ptr<Command> OpenFileCommand;
};
#endif
