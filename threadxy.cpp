#include "threadxy.h"
#include <stdio.h>
#include <stdlib.h>


threadxy::threadxy()
{

}
void threadxy::run()
{
    if(flag == 0)
     {
        printf("th c1 is:%d\n",c1);
        if(c1==1)
            system("honeyd -d -p nmap.prints -i eth0 -f hostlinux.conf");
        else if(c1==2)
            system("honeyd -d -p nmap.prints -i eth0 -f hostxp.conf");
        else if(c1==3)
            system("honeyd -d -p nmap.prints -i eth0 -f hostwinnt.conf");
    }
    else
    {
        if(c2==0)
          system("honeyd -d -p nmap.prints -i eth0 -f httpapach.conf");
        else if(c2==1)
          system("honeyd -d -p nmap.prints -i eth0 -f httpiis.conf");

    }
}
void threadxy::stop()
{
    system("pkill honeyd");
}
