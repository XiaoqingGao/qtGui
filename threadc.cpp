#include "threadc.h"

ThreadC::ThreadC()
{

}
void ThreadC::run()
{
    system("honeyd -d -i eth0 -f route.conf");
}

void ThreadC::stop()
{
    system("pkill honeyd");
}
