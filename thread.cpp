#include <QtCore>
#include <iostream>

#include "thread.h"
#include "widget.h"
#include <QMessageBox>
Thread::Thread()
{

}

void Thread::run()
{
    char buf2[30];
    printf("%d %d %d %d\n", a1, a2, a3, a4);
    sprintf(buf2, "./IPMAC %d %d %d %d", a1,a2,a3,a4);
    system(buf2);

}
void Thread::stop()
{
    system("pkill IPMAC");

}
