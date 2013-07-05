#ifndef THREADC_H
#define THREADC_H

#include <QThread>

class ThreadC : public QThread
{
    Q_OBJECT

public:
    char a1[20], a2[20], a3[20];
    int a4,a5;
public:
    ThreadC();
    void stop();

protected:
    void run();

};


#endif // THREADC_H
