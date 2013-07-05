#include <QHBoxLayout>
#include <QVBoxLayout>
#include "widget.h"
#include <QtGui>

FunctionWidget::FunctionWidget(QWidget *parent)
    :QDialog(parent)
{

    setObjectName(tr("functionWidget"));
    a = new  FuncScanPage;
    b = new  FuncGuardPage;
    c = new  FuncUpdatePage;
    d = new  FuncToolsPage;

    funcPages = new QStackedWidget;
    funcPages->addWidget(a);
    funcPages->addWidget(b);
    funcPages->addWidget(c);
    funcPages->addWidget(d);

    scanButton = new QPushButton;
    scanButton->setObjectName(tr("scanButton"));
    //scanButton->setText(tr("主页"));
    scanButton->setFlat(true);
    scanButton->setIcon(QIcon(":/images/zhuye.png"));
    scanButton->setIconSize(QSize(120,90));
    connect(scanButton,SIGNAL(clicked()),this,SLOT(setScanPage()));

    guardButton = new QPushButton;
    guardButton->setObjectName(tr("guardButton"));
    //guardButton->setText(tr("虚拟化网络"));
    guardButton->setFlat(true);
    guardButton->setIcon(QIcon(":/images/zhencha.png"));
    guardButton->setIconSize(QSize(120,90));
    connect(guardButton,SIGNAL(clicked()),this,SLOT(setGuardPage()));

    updateButton = new QPushButton;
    updateButton->setObjectName(tr("updateButton"));
    //updateButton->setText(tr("内核隐身"));
    updateButton->setFlat(true);
    updateButton->setIcon(QIcon(":/images/xuni.png"));
    updateButton->setIconSize(QSize(120,90));
    connect(updateButton,SIGNAL(clicked()),this,SLOT(setUpdatePage()));

    toolsButton = new QPushButton;
    toolsButton->setObjectName(tr("toolsButton"));
    //toolsButton->setText(tr("监控日志"));
    toolsButton->setFlat(true);
    toolsButton->setIcon(QIcon(":/images/rizhi.png"));
    toolsButton->setIconSize(QSize(120,90));
    connect(toolsButton,SIGNAL(clicked()),this,SLOT(setToolsPage()));


    QHBoxLayout *funcBtnLayout = new QHBoxLayout;
    funcBtnLayout->setMargin(0);

    funcBtnLayout->setAlignment(Qt::AlignTop);

    funcBtnLayout->addWidget(scanButton);
    funcBtnLayout->addWidget(guardButton);
    funcBtnLayout->addWidget(updateButton);
    funcBtnLayout->addWidget(toolsButton);

    funcBtnLayout->addStretch(1);



    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(funcBtnLayout);
    mainLayout->setSpacing(0);   //
    mainLayout->addWidget(funcPages);
    //mainLayout->addStretch(1);
    setLayout(mainLayout);
}

void FunctionWidget::setScanPage()
{
    funcPages->setCurrentIndex(0);
}
void FunctionWidget::setGuardPage()
{
    funcPages->setCurrentIndex(1);
}
void FunctionWidget::setUpdatePage()
{
    funcPages->setCurrentIndex(2);
}
void FunctionWidget::setToolsPage()
{
    funcPages->setCurrentIndex(3);
}
