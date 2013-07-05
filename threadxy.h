#ifndef THREADXY_H
#define THREADXY_H
#include <QThread>

class threadxy : public QThread
{
       Q_OBJECT
public:
    threadxy();

    void stop();
        int flag;
       int c2, c1;
protected:
    void run();


};
#endif // THREADXY_H

