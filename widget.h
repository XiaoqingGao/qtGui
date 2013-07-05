#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>
#include <QStackedWidget>
#include <QPushButton>
#include "funcguardpage.h"
#include "funcscanpage.h"
#include "functoolspage.h"
#include "funcupdatepage.h"

class FunctionWidget:public QDialog
{
    Q_OBJECT
public:
    FunctionWidget(QWidget *parent = 0);
    ~FunctionWidget(){}
public:
    QPushButton *scanButton;
    QPushButton *guardButton;
    QPushButton *updateButton;
    QPushButton *toolsButton;
    QStackedWidget *funcPages;
    FuncScanPage *a;
    FuncGuardPage *b;
    FuncUpdatePage *c;
    FuncToolsPage *d;


public slots:
    void setScanPage();
    void setGuardPage();
    void setUpdatePage();
    void setToolsPage();

};

#endif // WIDGET_H
