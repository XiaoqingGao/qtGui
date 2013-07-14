#ifndef FUNCGUARDPAGE_H
#define FUNCGUARDPAGE_H
#include <QtGui>
#include "thread.h"
#include "threadb.h"
#include "threadcz.h"
#include "threadxy.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/ipc.h>
#include <sys/socket.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct ipstr
{
    struct in_addr ip;
    int flag;
};
struct send
{
    char table1[20];
    char table2[20];
    int  table3;
    int  table4;
};

class FuncGuardPage:public QWidget
{
    Q_OBJECT
public:
    FuncGuardPage(QWidget *parent = 0);
    ~FuncGuardPage(){}
    QPushButton *makeButton;
    QPushButton *xnButton;
    QPushButton *xnfwButton;
    QPushButton *selectButton;
    QPushButton *stopButton;

    QPushButton *ksButton;
    QPushButton *tzButton;
    QPushButton *czButton;

    QLineEdit *numberLine1;
    QLineEdit *numberLine2;
    QLineEdit *numberLine3;
    QLineEdit *numberLine4;

    QTableWidget *tableWidget2;
    QTableWidget *tableWidget;
    QTableWidgetItem *checkBox;
    QTimer *timer;
    Thread threadA;
    ThreadB threadB;
    //threadcz threadC;
    threadxy threadD;
    int a1, a2, a3, a4;


    QCheckBox *w, *l, *m, *r, *b;

    struct send value[200];
   // friend class Thread;
    int row2;
    int m1;


public slots:
    void  get_interface();
        void  controlButton();
        void  sendButton();
        void  stopThread();
        void  changeTest(int ,int);
        void changed(int);
        void  xnfw();
        void  tc();
        void server(int, int);
        void startxy();
        void startcz();
        void stopinsmod2();
        void ww(int);
        void yy(int);

public:
    void second();
    int *ran(int *, int);
    void fileadd(char *);
    void delfile(int);

};
#endif // FUNCGUARDPAGE_H
