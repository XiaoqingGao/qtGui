#ifndef FUNCSCANPAGE_H
#define FUNCSCANPAGE_H
#include <QtGui>
#include "thread.h"
class FuncScanPage:public QWidget
{
    Q_OBJECT

public:
    FuncScanPage(QWidget *parent = 0);
    ~FuncScanPage(){}
    Thread thread1;

private:

protected:
    void first();
public slots:
    void xs();
    void ys();

};
#endif // FUNCSCANPAGE_H
