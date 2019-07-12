#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow():
    QMainWindow()
{
    resize(QSize(960, 600));

    //QPalette palette(this->palette());
    //palette.setColor(QPalette::Window, Qt::gray);
    //this->setPalette(palette);

    CreateStatusBar();
    CreateMenuAndToolBar();
    CreatePicLabel();
    CreatePlayButton();
    SetTimer();
    SetSlider();
    SetLayer();
}

void MainWindow::CreateStatusBar()
{
    QLabel *statusLabel = new QLabel();
    //statusLabel->setFrameShadow()
    QPalette palette(statusLabel->palette());
    palette.setColor(QPalette::Window, Qt::black);
    statusLabel->setPalette(palette);
    statusBar()->addWidget(statusLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border:0px;}"));
}

void MainWindow::CreateMenuAndToolBar()
{
    //File MenuBar and ToolBar
    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    QToolBar *fileTool = addToolBar(tr("File"));

    //open file action
    QAction *openAction = new QAction(QIcon("../image/open.png"), tr("Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a vedio file"));
    fileMenu->addAction(openAction);
    fileTool->addAction(openAction);
    connect(openAction, &QAction::triggered, this, &MainWindow::OpenOperation);

    //save file as current file action
    QAction *saveAction = new QAction(QIcon("../image/save.png"), tr("Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the file as current file"));
    fileMenu->addAction(saveAction);
    fileTool->addAction(saveAction);
    connect(saveAction, &QAction::triggered, this, &MainWindow::SaveOperation);

    //save file as another file action
    QAction *saveAsAction = new QAction(QIcon("../image/saveas.png"), tr("Save As..."), this);
    saveAsAction->setShortcuts(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the file as another file"));
    fileMenu->addAction(saveAsAction);
    fileTool->addAction(saveAsAction);
    connect(saveAsAction, &QAction::triggered, this, &MainWindow::SaveAsOperation);

    //add a separator before "exit" in menu
    fileMenu->addSeparator();

    //exit action in file menu
    QAction *exitAction = new QAction(tr("Exit"));
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit now"));
    fileMenu->addAction(exitAction);
    connect(exitAction, &QAction::triggered, this, &MainWindow::ExitOperation);


    //about menu
    QMenu *aboutMenu = menuBar()->addMenu(tr("About"));

    //help action in about menu
    QAction *helpAction = new QAction(QIcon("../image/help.png"), tr("Help"), this);
    helpAction->setStatusTip(tr("How to use"));
    aboutMenu->addAction(helpAction);
    connect(helpAction, &QAction::triggered, this, &MainWindow::HelpOperation);

    //about us action in about menu
    QAction *aboutUsAction = new QAction(tr("About us..."), this);
    aboutUsAction->setStatusTip("The developers");
    aboutMenu->addAction(aboutUsAction);
    connect(aboutUsAction, &QAction::triggered, this, &MainWindow::AboutUsOperation);

    //statusBar()->showMessage(" ");
}

//for test
void MainWindow::CreatePicLabel()
{
    pic = new QLabel();
    QPalette pale(pic->palette());
    pale.setColor(QPalette::Window, Qt::black);
    pic->setPalette(pale);
    pic->setAutoFillBackground(true);

    pic->setScaledContents(true);
    //layout()->addWidget(pic);
}

void MainWindow::CreatePlayButton()
{
    button = new QPushButton(tr("开始"));
    //layout()->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(OnClick()));
}

void MainWindow::SetTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
}

void MainWindow::SetLayer()
{
    QWidget *widget = new QWidget(this);
    QHBoxLayout *hLayout = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout();

    hLayout->addWidget(start);
    hLayout->addWidget(slider);
    hLayout->addWidget(end);

    vLayout->addWidget(pic);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(button);
    widget->setLayout(vLayout);
    setCentralWidget(widget);
}

void MainWindow::SetSlider()
{
    slider = new QSlider(Qt::Horizontal);
    slider->setMaximum(6000);
    slider->setMinimum(0);
    slider->setValue(0);
    slider->setFixedSize(QSize(860, 30));
    //slider->setSingleStep(1);
    //slider->setStyleSheet(QString("QSlider::handle{border-radius:10px;}"));

    start = new QLineEdit("00:00");
    end = new QLineEdit("100:00");
    start->setStyleSheet(QString("background:transparent;border-style:outset;border-width:0"));
    end->setStyleSheet(QString("background:transparent;border-style:outset;border-width:0"));
    start->setEnabled(false);
    end->setEnabled(false);
    start->setFocusPolicy(Qt::NoFocus);
    end->setFocusPolicy(Qt::NoFocus);
    start->setFixedSize(QSize(50, 30));
    end->setFixedSize(QSize(50, 30));
    start->setAlignment(Qt::AlignHCenter);
    end->setAlignment(Qt::AlignHCenter);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(SetLineEditValue()));
}

void MainWindow::SetLineEditValue()
{
    int pos = slider->value();
    QString str = QString("%1:%2").arg(pos / 60, 2, 10, QLatin1Char('0')).arg(pos % 60, 2, 10, QLatin1Char('0'));
    start->setText(str);
}

void MainWindow::OnTimer()
{
//    static double angle = 0;
//
//    picture = new QPixmap("E:\\C++\\project\\MiniPremiere\\image\\zju.png");
//    picture->scaled(pic->size(), Qt::KeepAspectRatio);
//    pic->setPixmap(*picture);
//    //pic->setAlignment(Qt::AlignHCenter);
//
//    angle += 0.1;
//    static int i = 1;
//    cv::Mat mat;
//
//    std::string test_string = "../video/test.mp4";
//    EditableVideo test(test_string);
//    mat = test.getNextImage();
//
//    if(i == 1){
//        image = FromCVtoQImage(mat);
//        i == 0;
//    }
//
//    picture = QPixmap::fromImage(image);
//    picture.scaled(pic->size(), Qt::KeepAspectRatio);
//    pic->setPixmap(picture);

}

void MainWindow::OnClick()
{
    static int j = 1;
    if(j == 1){
        j = 0;
        button->setText(tr("暂停"));
        timer->start(300);
    }
    else{
        j = 1;
        button->setText(tr("开始"));
        timer->stop();
    }
}

//void MainWindow::SetOpenFileCommand(std::shared_ptr<Command> OpenFileCommand)
//{
//    this->OpenFileCommand = OpenFileCommand;
//}

//need to be updated
void MainWindow::OpenOperation()
{
    //OpenFileCommand->Setparameters(std::string FilePath);
    //OpenFileCommand->Exec();
    qDebug() << "Press Open" << endl;
}

void MainWindow::SaveOperation()
{
    qDebug() << "Press Save" << endl;
}

void MainWindow::SaveAsOperation()
{
    qDebug() << "Press Save As" << endl;
}

void MainWindow::ExitOperation()
{
    qDebug() << "Press Exit" << endl;
}

void MainWindow::HelpOperation()
{
    qDebug() << "Press Help" << endl;
}

void MainWindow::AboutUsOperation()
{
    qDebug() << "Press About us" << endl;
}