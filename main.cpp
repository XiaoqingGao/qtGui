#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include <QSplashScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/www.png"));
    w.show();
    return a.exec();
}
