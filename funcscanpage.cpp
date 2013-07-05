#include "funcscanpage.h"
#include <QtGui>

FuncScanPage::FuncScanPage(QWidget *parent)
    :QWidget(parent)
{

//    QLabel *label = new QLabel();
//    QMovie *movie =new QMovie(":/images/dt.gif");
//    label->setMovie(movie);
//    movie->start();


    setObjectName(tr("scanPage"));



        QPixmap pixmap1(":/images/33.png");
        QPixmap pixmap = pixmap1 .scaled(840,470);
        QPalette palette;
        //pixmap->resize(this->size());
        palette.setBrush(this->backgroundRole(), QBrush(pixmap));
        this->setPalette(palette);
        this->setAutoFillBackground(true);

        QLabel *label = new QLabel();

        QPushButton *xgButton = new QPushButton(tr(""));

        xgButton->setFlat(true);
        xgButton->setIcon(QIcon(":/images/22.png"));
        xgButton->setIconSize(QSize(200,200));
        QHBoxLayout *mainLayout2 = new QHBoxLayout;
        mainLayout2->addSpacing(40);
         mainLayout2->addWidget(xgButton);
        mainLayout2->addWidget(label);
          setLayout(mainLayout2);



//        QLabel *label = new QLabel();
//               QPushButton *xgButton = new QPushButton(tr(""));
//               xgButton->setFlat(true);
//               xgButton->setIcon(QIcon(":/images/yinshen.png"));
//               xgButton->setIconSize(QSize(168,56));

//               QPushButton *xg1Button = new QPushButton(tr(""));
//               xg1Button->setFlat(true);
//               xg1Button->setIcon(QIcon(":/images/xianshen.png"));
//               xg1Button->setIconSize(QSize(168,56));
//               connect(xgButton,SIGNAL(clicked()),this,SLOT(xs()));
//                connect(xg1Button,SIGNAL(clicked()),this,SLOT(ys()));
//                QLabel *label1 = new QLabel();
//                QLabel *label2 = new QLabel();
//                QLabel *label4 = new QLabel();

//                  QLabel *label3= new QLabel();
//                  QLabel *label5= new QLabel();

//                QHBoxLayout *mainLayout = new QHBoxLayout;

//                mainLayout->addWidget(label);
//                mainLayout->addWidget(label2);
//                mainLayout->addWidget(label4);
//                mainLayout->addWidget(xgButton);
//                mainLayout->addWidget(xg1Button);
//                  mainLayout->addWidget(label1);

//                  QVBoxLayout *mainLayout2 = new QVBoxLayout;
//                  mainLayout2->addWidget(label5);
//                   mainLayout2->addWidget(label3);

//                   mainLayout2->addLayout(mainLayout);


//                setLayout(mainLayout2);

                first();


}
void FuncScanPage::first()
{

}
void FuncScanPage::xs()
{
    thread1.a1=25;
    thread1.a2=15;
    thread1.a3=1200;
    thread1.a4=0;
    thread1.start();

}
void FuncScanPage::ys()
{
    thread1.stop();
    thread1.terminate();
}
