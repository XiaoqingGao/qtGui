#ifndef THREADCZ_H
#define THREADCZ_H
#include <QThread>
class threadcz : public QThread
{
       Q_OBJECT
public:
    threadcz();

    void stop();
      int c1;

protected:
    void run();


};

#endif // THREADCZ_H

