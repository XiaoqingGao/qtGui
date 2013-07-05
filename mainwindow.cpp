#include <QDebug>
#include <QFile>
#include <QDragMoveEvent>
#include <QMenu>
#include <QMenuBar>
#include "mainwindow.h"
#include "widget.h"
#include <QBitmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    :QFrame(parent)
{

    setWindowFlags(Qt::FramelessWindowHint);
    // Don't let this widget inherit the parent's backround color
      setAutoFillBackground(true);
            // Use a brush with a Highlight color role to render the background
          //  setBackgroundRole(QPalette::Highlight);
    //setWindowOpacity(0.9); //
    resize(850,600);
    setMinimumWidth(850);
    setMinimumHeight(600);
    setObjectName(tr("MainWindow"));
    setWindowModality(Qt::WindowModal);


    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/images/cc.png")));
    this->setPalette(palette);
    this->setAutoFillBackground(true);



    appMinButton = new QPushButton();
    appMinButton->setToolTip(tr("最小化"));
        appMinButton->setCursor(Qt::PointingHandCursor);

        QFile file(":/images/styleTest.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
        file.close();

        appTitle = new QLabel();
        appTitle->setText(tr("网络隐形系统"));
        appTitle->setObjectName(tr("appTitle"));
        appTitle->setContentsMargins(7, 0, 0, 0);

        appMinButton = new QPushButton();
        appMinButton->setObjectName(tr("appMinButton"));
        connect(appMinButton, SIGNAL(clicked()), this, SLOT(showMinimized()));

        appCloseButton = new QPushButton();
        appCloseButton->setObjectName(tr("appCloseButton"));
        appCloseButton->setToolTip(tr("关闭"));
        appCloseButton->setCursor(Qt::PointingHandCursor);
        connect(appCloseButton, SIGNAL(clicked()), this, SLOT(close()));




        hBoxLayout1 = new QHBoxLayout;
        hBoxLayout1->setAlignment(Qt::AlignTop|Qt::AlignRight);  //°?Å¥×éLayoutÓÒ¶ÔÆë+ÖÃ¶¥
        hBoxLayout1->setSpacing(0);                              //Èý?ö°?Å¥Ö®?äµÄ·ìÏ¶Îª0px
        hBoxLayout1->setContentsMargins(0, 0, 10, 0);            //ÉèÖÃ°?Å¥×éÀëÓÖ±ß?çµÄ?àÀëÎª10px
        //hBoxLayout1->addWidget(styleChangeButton);
        //hBoxLayout1->addWidget(appMenuButton);
        hBoxLayout1->addWidget(appMinButton);
        hBoxLayout1->addWidget(appCloseButton);

        hTopLayout = new QHBoxLayout;
        hTopLayout->addWidget(appTitle);
        hTopLayout->addLayout(hBoxLayout1);
        hTopLayout->setAlignment(Qt::AlignTop);
        hTopLayout->setMargin(0);

        /*×?Ì¬Ìõ*/
        QHBoxLayout *statusBar = new QHBoxLayout;
        programVersion = new QLabel(tr("程序版本 1"));
        dateOfLibs = new QLabel(tr("日期 2012-08-06\t"));
        checkUpdate = new QLabel(tr("<a style=\"text-decoration:underline;\">检查更新</a>"));

        statusBar->setAlignment(Qt::AlignBottom);
        statusBar->setMargin(3);
        statusBar->addSpacing(10);
        statusBar->addWidget(programVersion);
        statusBar->addSpacing(200);
        statusBar->addWidget(dateOfLibs);
        statusBar->addSpacing(250);
        statusBar->addWidget(checkUpdate);
        //statusBar->addStretch(1);
        //statusBar->addWidget(connectStatus);

        FunctionWidget *functions = new FunctionWidget;

        vBoxLayout = new QVBoxLayout;
        vBoxLayout->setMargin(0);
        vBoxLayout->addLayout(hTopLayout);
       // vBoxLayout->addSpacing(4);
        vBoxLayout->addWidget(functions);
        vBoxLayout->setSpacing(0);

        //vBoxLayout->addStretch(1);
        //vBoxLayout->addSpacing(1);
        vBoxLayout->addLayout(statusBar);

        /*ÉèÖÃ¶¥²¿?°Ìå²??Ö*/
        setLayout(vBoxLayout);
    }

    //µã»÷Êó±êÊ±?ÇÂ?Êó±êµÄÎ»ÖÃ£¬ÓÃÓÚÊó±êµÄÒÆ¶¯
    void MainWindow::mousePressEvent(QMouseEvent *event)
    {

        oldMousePos = event->globalPos() - this->pos();
        event->ignore();
    }

    //ÊµÏÖ?çÃæµÄÍÏ¶¯
    void MainWindow::mouseMoveEvent(QMouseEvent *event)
    {
        if(event->y()<50||event->x()<50||rect().width()-event->x()<5)
        {
            move(event->globalPos()-oldMousePos);
        }
        event->ignore();
    }

