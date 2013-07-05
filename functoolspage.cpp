
#include "shm_com.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "widget.h"
#include <QFileDialog>
#include <QtGui>
#include <QStackedWidget>
#include <QtGui>
#include <qstring.h>
#include <qfile.h>
#include <QTextStream>
#include <qtextstream.h>
#include <qtextcodec.h>
#include <QMovie>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#include <qvalidator.h>

#include "functoolspage.h"

FuncToolsPage::FuncToolsPage(QWidget *parent)
    :QWidget(parent)
{
        setObjectName(tr("toolsPage"));
        this->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/images/1fine1.png")));
        this->setPalette(palette);


        QGroupBox *packagesGroup = new QGroupBox(tr("可疑IP地址"));

            text3 = new QTextBrowser;
            text3->setFixedSize(350,150);

                QPushButton *glButton = new QPushButton(tr("控制可疑IP"));
                QPushButton *xgButton = new QPushButton(tr("显示列表"));
                QPushButton *xzButton = new QPushButton(tr("停止探测可疑IP"));

//                xgButton->setEnabled(false);
//                xzButton->setEnabled(false);


                connect(glButton,SIGNAL(clicked()),this,SLOT(startinsmod()));
                connect(xgButton,SIGNAL(clicked()),this,SLOT(startxs()));
                connect(xzButton,SIGNAL(clicked()),this,SLOT(stopinsmod()));

                QVBoxLayout *updateLayout3 = new QVBoxLayout;
                updateLayout3->addWidget(glButton);
                updateLayout3->addWidget(xgButton);
                updateLayout3->addWidget(xzButton);

                QHBoxLayout *mainLayout3 = new QHBoxLayout;
                mainLayout3->addWidget(text3);
                mainLayout3->addLayout(updateLayout3);

                QVBoxLayout *configLayout = new QVBoxLayout;
                configLayout->addLayout(mainLayout3);
                packagesGroup->setLayout(configLayout);

        QGroupBox *updateGroup1 = new QGroupBox(tr("虚拟服务日志"));
        text2 = new QTextBrowser;
        text2->setFixedSize(400,150);
        comboBox = new QComboBox(this);
          comboBox->resize(100, 20);

          comboBox->addItem("chglog.txt");
          comboBox->addItem("ftp.log");
          comboBox->addItem("iss.log");
          comboBox->addItem("pop3.log");
          comboBox->addItem("smtp.log");
          comboBox->addItem("web.log");

          connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChanged(int)));
//          QHBoxLayout *updateLayout5 = new QHBoxLayout;
//          updateLayout5->addSpacing(30);
//          updateLayout5->addWidget(comboBox);
//          updateLayout5->addSpacing(250);

          QHBoxLayout *updateLayout6 = new QHBoxLayout;
          //updateLayout6->addLayout(updateLayout5);
          updateLayout6->addWidget(text2);
          updateLayout6->addWidget(comboBox);

          QVBoxLayout *updateLayout7 = new QVBoxLayout;
          updateLayout7->addLayout(updateLayout6);
          updateGroup1->setLayout(updateLayout7);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(packagesGroup);
        mainLayout->addWidget(updateGroup1);

        QLabel *label = new QLabel;
        QPixmap icon(":/images/ee.png");
        label->setPixmap(icon);

        QHBoxLayout *mainLayout1 = new QHBoxLayout;
        mainLayout1->addWidget(label);
        mainLayout1->addLayout(mainLayout);


        setLayout(mainLayout1);


}


void FuncToolsPage::onChanged(int i)
{
    if(comboBox->itemText(i) == "chglog.txt")
    {
        QString a = "./"+(comboBox->itemText(i));
        QFile file(a);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            QString strFileContent = QString::fromUtf8(file.readAll());
            text2->setText(strFileContent);
            file.close();
        }
    }
    else
    {
            QString a = "/usr/local/share/honeyd/log/"+(comboBox->itemText(i));
            QFile file(a);
                if(file.open(QIODevice::ReadOnly | QIODevice::Text))
                {

                    QString strFileContent = QString::fromUtf8(file.readAll());
                    text2->setText(strFileContent);
                    file.close();
                }
    }
}
void FuncToolsPage::startinsmod()
{

    system("insmod ./kernelmodule20120811/stealth/stkernel.ko");
    QMessageBox::information(this, tr("探测可疑IP"), tr("探测可疑IP成功"));
//        glButton->setEnabled(false);
//        xgButton->setEnabled(true);
//        xzButton->setEnabled(true);



}
void FuncToolsPage::startxs()
{
        QFile file( "/proc/ss_blacklist" );

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            QString strFileContent = QString::fromUtf8(file.readAll());
            text3->setText(strFileContent);
            file.close();
        }
}

void FuncToolsPage::stopinsmod()
{
    system("rmmod ./kernelmodule20120811/stealth/stkernel");
    QMessageBox::information(this, tr("探测可疑IP"), tr("探测可疑IP成功"));
//    glButton->setEnabled(true);
//    xgButton->setEnabled(false);
//    xzButton->setEnabled(false);
}
