#include "threadcz.h"

threadcz::threadcz()
{

}
void threadcz::run()
{
    if(c1==0)
        system("honeyd -d -p nmap.prints -i eth0 -f hostxp.conf");
    else if(c1==1)
        system("honeyd -d -p nmap.prints -i eth0 -f hostlinux.conf");
    else if(c1==2)
        system("honeyd -d -p nmap.prints -i eth0 -f hostwinnt.conf");

}
void threadcz::stop()
{
    system("pkill honeyd");
}
