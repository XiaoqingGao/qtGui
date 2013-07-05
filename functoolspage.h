#ifndef FUNCTOOLSPAGE_H
#define FUNCTOOLSPAGE_H
#include <QtGui>
class FuncToolsPage:public QWidget
{
    Q_OBJECT
public:
    FuncToolsPage(QWidget *parent = 0);
    ~FuncToolsPage(){}
    QTextBrowser *text3;
    QTextBrowser *text2;
    QComboBox *comboBox;
 QPushButton *glButton;
 QPushButton *xgButton;
 QPushButton *xzButton;

public slots:
//    void show();
    void startinsmod();
    void stopinsmod();
    void startxs();
    void onChanged(int);
//    void dele();
};

#endif // FUNCTOOLSPAGE_H
