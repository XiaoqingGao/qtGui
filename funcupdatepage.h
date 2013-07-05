#ifndef FUNCUPDATEPAGE_H
#define FUNCUPDATEPAGE_H
#include <QtGui>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "threadc.h"
struct send1
{
    char table1[20];
    char table2[20];
    int  table3;
    int  table4;
};
class FuncUpdatePage:public QWidget
{
    Q_OBJECT
public:
    FuncUpdatePage(QWidget *parent = 0);
    ~FuncUpdatePage(){}
 QTableWidget *tableWidget;
    QTextBrowser *text3;
    QPushButton *glButton;
    QPushButton *qButton;

    QPushButton *xgButton;
    QPushButton *xzButton;

    QPushButton *xzButton2;
    QPushButton *startButton;
    QPushButton *stopButton;

    QLineEdit *numberLine1;
    QLineEdit *numberLine2;
   //QLineEdit *numberLine3;
    QLineEdit *numberLine4;
    QLineEdit *numberLine5;
    QString a1, a2;
    int a4, a5;
    int k;////总IP地址总数
    int np;//单机按钮次数
    int n_buf[255];//存放虚假主机坐标
    char Localroute[20];
    int name_n;
    char routA_addr[3][100];
    //char routB_addr[100];


    ThreadC threadC;


    struct send1 value[200];
public slots:
    void addB();
    void  changeTest(int ,int);
    void server(int, int);
    void start_route();
    void stop_route();

protected:

    void third ();
};


#endif // FUNCUPDATEPAGE_H
