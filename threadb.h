#ifndef THREADB_H
#define THREADB_H

#include <QThread>



class ThreadB : public QThread
{
    Q_OBJECT

public:


public:
    ThreadB();


    void stop();

protected:
    void run();


};


#endif // THREADB_H
