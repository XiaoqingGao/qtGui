
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui/QMainWindow>
#include <QtGui/QDialog>
#include <QtGui/QButtonGroup>
#include <QtGui/QPushButton>
#include <QToolButton>
#include <QtGui/QStatusBar>
#include <QtGui/QLabel>
#include <QHBoxLayout>

class MainWindow:public QFrame
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow(){}
private:
    QLabel *appTitle;
    QPushButton *styleChangeButton;
    QToolButton *appMenuButton;
    QPushButton *appMinButton;

    QPushButton *appCloseButton;

    QHBoxLayout *hBoxLayout1;
    QVBoxLayout *vBoxLayout;
    QHBoxLayout *hTopLayout;
    QHBoxLayout *testLayout1;
    QHBoxLayout *testLayout2;

    QStatusBar *statusBar;
    QLabel *programVersion;
    QLabel *dateOfLibs;
    QLabel *connectStatus;
    QLabel *checkUpdate;



protected:
    QPoint oldMousePos;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
