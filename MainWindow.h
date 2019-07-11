#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QVBoxLayout>
#include <iostream>
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


class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow();
    void CreateMenuAndToolBar();
    void CreateStatusBar();
    //for test
    void CreatePicLabel();
    void CreatePlayButton();
    void SetTimer();
    void SetSlider();
    void SetLayer();

private:
    void OpenOperation();
    void SaveOperation();
    void SaveAsOperation();
    void ExitOperation();
    void HelpOperation();
    void AboutUsOperation();

private:
    //for test
    QPushButton *button;
    QLabel *pic;
    QSlider *slider;
    QLabel *start;
    QLabel *end;
    //QStringList name;
    QTimer *timer;
    QPixmap *picture;
private slots:
    void on_click();
    void on_timer();
};

#endif
