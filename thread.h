#ifndef THREAD_H
#define THREAD_H

#include <QThread>



class Thread : public QThread
{
    Q_OBJECT

public:
    int a1;
    int a2;
    int a3;
    int a4;

public:
    Thread();


    void stop();

protected:
    void run();


};




#endif // THREAD_H
