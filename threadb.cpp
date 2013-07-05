#include "threadb.h"

ThreadB::ThreadB()
{

}
void ThreadB::run()
{
    char buf[]="honeyd -d -p nmap.prints -i eth0 -f syshost.conf  ";
    system(buf);
}
