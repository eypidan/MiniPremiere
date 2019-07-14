#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow():
    QMainWindow()
{
    resize(QSize(960, 600));

    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, qRgb(200, 200, 200));
    this->setPalette(palette);

    CreateStatusBar();
    CreateMenuAndToolBar();
    CreatePicLabel();
    CreatePlayButton();
    SetTimer();
    SetSlider();
    SetLayer();

    TheUpdateViewNotification = std::make_shared<UpdateViewNotification>(this);

    isLoaded = 0;
}

void MainWindow::CreateStatusBar()
{
    QLabel *statusLabel = new QLabel();
    //statusLabel->setFrameShadow()
    QPalette palette(statusLabel->palette());
    palette.setColor(QPalette::Window, Qt::gray);
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
    QAction *openAction = new QAction(QIcon("../View/image/open.png"), tr("Open..."), this);
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
    pic = new QLabel(tr("MiniPlayer"));
    pic->setAlignment(Qt::AlignCenter);
    pic->setFont(QFont("Microsoft YaHei", 40, 75));
    QPalette pale(pic->palette());
    pale.setColor(QPalette::Window, qRgb(100,100,100));
    pale.setColor(QPalette::WindowText, qRgb(150,150,150));
    pic->setPalette(pale);
    pic->setAutoFillBackground(true);
    pic->setMaximumSize(1350, 540);
    pic->setScaledContents(true);
    //layout()->addWidget(pic);
}

void MainWindow::CreatePlayButton()
{
    button = new QPushButton();
    button->setIcon(QIcon("../View/image/play.png"));
    button->setIconSize(QSize(40, 40));
    button->setStyleSheet(QString("QPushButton{border-radius:35px;}"));
    //layout()->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(OnClick()));

    speeddown = new QPushButton();
    speeddown->setIcon(QIcon("../View/image/speeddown.png"));
    speeddown->setIconSize(QSize(40, 40));
    speeddown->setStyleSheet(QString("QPushButton{border-radius:35px;}"));

    speedup = new QPushButton();
    speedup->setIcon(QIcon("../View/image/speedup.png"));
    speedup->setIconSize(QSize(40, 40));
    speedup->setStyleSheet(QString("QPushButton{border-radius:35px;}"));
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
    QHBoxLayout *hLayout_button = new QHBoxLayout();


    hLayout->addWidget(start);
    hLayout->addWidget(slider);
    hLayout->addWidget(end);

    vLayout->addWidget(pic);
    vLayout->addLayout(hLayout);

    hLayout_button->addStretch();
    hLayout_button->addWidget(speeddown);
    hLayout_button->addWidget(button);
    hLayout_button->addWidget(speedup);
    hLayout_button->addStretch();
    hLayout_button->setSpacing(10);

    vLayout->addLayout(hLayout_button);
    widget->setLayout(vLayout);
    setCentralWidget(widget);
}

void MainWindow::SetSlider()
{
    slider = new QSlider(Qt::Horizontal);
    slider->setOrientation(Qt::Horizontal);
    slider->setMaximum(0);
    slider->setMinimum(0);
    slider->setValue(0);
    slider->setStyleSheet(QString("QSlider::handle:horizontal{border:0;width: 15px;margin: -7px -7px -7px -7px;color:#808080} QSlider::sub-page:horizontal{background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:0, stop:0 #808080, stop:0.25 #808080, stop:0.5 #808080, stop:1 #808080);}"));

    start = new QLineEdit("00:00");
    end = new QLineEdit("00:00");
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
    static int amount = 0;

    FetchQImageCommand->Exec();

    if(amount == *framerate && amount != 0){
        amount = 0;
        slider->setValue(slider->value() + 1);
    }
    amount++;

    //play over
    if(slider->value() == *timeduration / 1000000 && amount == *framerate){
        slider->setValue(0);
        timer->stop();
        start->setText(QString("00:00"));
        button->setIcon(QIcon("../View/image/play.png"));
        isLoaded = 0;
    }
}

void MainWindow::OnClick()
{
    static int flag = 0;

    if(!isLoaded){
        return;
    }

    if(flag == 1){
        flag = 0;
        button->setIcon(QIcon("../View/image/pause.png"));
        timer->start(100 / *framerate);
    }
    else{
        flag = 1;
        button->setIcon(QIcon("../View/image/play.png"));
        timer->stop();
    }
}

void MainWindow::UpdateQImage()
{
    picture = QPixmap::fromImage(*image);
    picture.scaled(pic->size(), Qt::KeepAspectRatioByExpanding);
    pic->setPixmap(picture);
}

void MainWindow::SetOpenFileCommand(std::shared_ptr<CommandBase> OpenFileCommand)
{
    this->OpenFileCommand = OpenFileCommand;
}

void MainWindow::SetFetchQImageCommand(std::shared_ptr<CommandBase> FetchQImageCommand){
    this->FetchQImageCommand = FetchQImageCommand;
}

void MainWindow::SetQImage(std::shared_ptr<QImage> image)
{
    this->image = image;
}

void MainWindow::SetTimeDuration(std::shared_ptr<int> timeduration)
{
    this->timeduration = timeduration;
}

void MainWindow::SetFrameRate(std::shared_ptr<int> framerate)
{
    this->framerate = framerate;
}

std::shared_ptr<Notification> MainWindow::GetUpdateViewNotification()
{
    return std::static_pointer_cast<Notification>(TheUpdateViewNotification);
}

//need to be updated
void MainWindow::OpenOperation()
{
    QString filepath = QFileDialog::getOpenFileName(this, tr("Open Video"), ".", tr("Video File(*.avi *.mp4)"));
    std::string path = filepath.toStdString();

    if(filepath == nullptr){
        return;
    }

    if(isLoaded){
        slider->setValue(0);
        timer->stop();
        start->setText(QString("00:00"));
        button->setIcon(QIcon("../View/image/play.png"));
        isLoaded = 0;
    }

    OpenFileCommand->SetParameters(path);
    OpenFileCommand->Exec();

    slider->setMaximum(*timeduration / 1000000);
    QString str = QString("%1:%2").arg(*timeduration / 1000000 / 60, 2, 10, QLatin1Char('0')).arg(*timeduration / 1000000 % 60, 2, 10, QLatin1Char('0'));
    end->setText(str);

    qDebug() << filepath << endl;

    isLoaded = 1;

    button->setIcon(QIcon("../View/image/pause.png"));
    timer->start(1000 / *framerate);
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
