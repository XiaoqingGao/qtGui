#include "funcupdatepage.h"
#include <QFileDialog>
#include <QtGui>
#include <QStackedWidget>
#include <QtGui>
#include <qstring.h>
#include <qfile.h>
#include <QTextStream>
#include <qtextstream.h>
#include <qtextcodec.h>
#include <QMovie>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "thread.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>


#include <qvalidator.h>

FuncUpdatePage::FuncUpdatePage(QWidget *parent)
    :QWidget(parent)
{
    setObjectName(tr("updatePage"));

        QPixmap pixmap1(":/images/1fine1.png");
        QPixmap pixmap = pixmap1 .scaled(840,470);
        QPalette palette;
        //pixmap->resize(this->size());
        palette.setBrush(this->backgroundRole(), QBrush(pixmap));
        this->setPalette(palette);
        this->setAutoFillBackground(true);
        k=0;
        np=0;
        name_n=0;
        for(int p=0;p<200;p++)
            {
            strcpy(value[p].table2,"21");
            value[p].table4=0;
            }


    //    this->setAutoFillBackground(true);
    //    QPalette palette;
    //    palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/images/dd.png")));
    //    this->setPalette(palette);

        third();

}
void FuncUpdatePage::third()
{
      QGroupBox *packagesGroup = new QGroupBox(tr("虚假路由详细信息"));

      QStringList labels;
      labels << tr("虚假路由") << tr("虚拟服务") << tr("是否静默");
      tableWidget = new QTableWidget;
      tableWidget->setColumnCount(3);
      tableWidget->setHorizontalHeaderLabels(labels);
      tableWidget->horizontalHeader()-> setResizeMode(QHeaderView::Stretch);
      //tableWidget->horizontalHeader()-> setResizeMode(QHeaderView::Stretch);

//      QStringList leafTextList;
//      leafTextList << "Leaf 1" << "1";
//      QTreeWidgetItem *leaf = new QTreeWidgetItem(root, leafTextList);
//      root->addChild(leaf);
//      QStringList leaf2TextList;
//      leaf2TextList << "Leaf 2" << "2";
//      QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root, leaf2TextList);
//      leaf2->setCheckState(0, Qt::Checked);
//      root->addChild(leaf2);


      QVBoxLayout *configLayout = new QVBoxLayout;
             configLayout->addWidget(tableWidget);
             packagesGroup->setLayout(configLayout);

        QGroupBox *xjGroup = new QGroupBox(tr("虚假路由"));

        QLabel *label1 = new QLabel(tr("虚假路由地址"));
        QLabel *label2 = new QLabel(tr("路由地址"));
        //QLabel *label3 = new QLabel(tr("路由地址B"));
        QLabel *label4 = new QLabel(tr("IP地址个数"));
        QLabel *label5 = new QLabel(tr("IP起始地址"));

        QLabel *label6 = new QLabel;
        QLabel *label7 = new QLabel;
        QLabel *label8 = new QLabel;
        //QLabel *label9 = new QLabel;
        QLabel *label10 = new QLabel;
         QLabel *label11 = new QLabel;

        numberLine1 = new QLineEdit;
        numberLine2 = new QLineEdit;
        //numberLine3 = new QLineEdit;
        numberLine4 = new QLineEdit;
        numberLine5 = new QLineEdit;

//        QComboBox *com = new QComboBox();
//            com->addItem(tr("思科路由"));
//            com->addItem("Linux");
//             com->addItem("Mac");

        QGridLayout *a = new QGridLayout;
        a->addWidget(label6,0,0);
        a->addWidget(label1,1,0);

        a->addWidget(numberLine1,1,1);
        numberLine1->setFixedSize(180,30);
        a->addWidget(label7,2,0);
        //connect(numberLine1, SIGNAL(textChanged()), this, SLOT(addip()));

        a->addWidget(label2,3,0);
        a->addWidget(numberLine2,3,1);
        numberLine2->setFixedSize(180,30);
        a->addWidget(label8,4,0);

//        a->addWidget(label3,5,0);
//        a->addWidget(numberLine3,5,1);

//        a->addWidget(label9,6,0);

        a->addWidget(label4,5,0);
        a->addWidget(numberLine4,5,1);
        numberLine4->setFixedSize(180,30);

        a->addWidget(label10,6,0);

        a->addWidget(label5,7,0);
        a->addWidget(numberLine5,7,1);
        numberLine5->setFixedSize(180,30);
        a->addWidget(label11,8,0);

        QPushButton *ks = new QPushButton(tr("添加路由"));
        connect(ks, SIGNAL(clicked()),this,SLOT(addB()));

        QPushButton *start_route = new QPushButton(tr("开始"));
        connect(start_route, SIGNAL(clicked()),this,SLOT(start_route()));

        QPushButton *stop_route = new QPushButton(tr("停止"));
        connect(stop_route, SIGNAL(clicked()),this,SLOT(stop_route()));

        QHBoxLayout *b = new QHBoxLayout;
        b->addSpacing(20);
        b->addWidget(ks);
        b->addSpacing(20);
        b->addWidget(start_route);
        b->addSpacing(20);
        b->addWidget(stop_route);

        QVBoxLayout *t = new QVBoxLayout;
        t->addLayout(a);
        t->addLayout(b);


        QVBoxLayout *t2 = new QVBoxLayout;
        t2->addLayout(t);
        xjGroup->setLayout(t2);

        QHBoxLayout *mainLayout = new QHBoxLayout;
        mainLayout->addWidget(xjGroup);
      // mainLayout->addStretch(50);
        mainLayout->addWidget(packagesGroup);

        connect(tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(changeTest(int, int)));
        connect(tableWidget, SIGNAL(cellChanged(int,int)), this, SLOT(server(int, int)));

        setLayout(mainLayout);
 }

void FuncUpdatePage::addB()
{

    a1= numberLine1->text();
    a2 = numberLine2->text();
    a4 = (numberLine4->text()).toInt();
    a5 = (numberLine5->text()).toInt();

     n_buf[np]=k;
     np=np+1;
    //k=k+a4+1;



    char rout_ip1[20];
    char rout_ip2[20];
    strcpy(Localroute,a1.toStdString().c_str());
    strcpy(rout_ip2,a2.toStdString().c_str());

    struct in_addr net_ip1,net_ip2;
    unsigned int temp2;
    char net_buf[20];
    temp2=inet_addr(rout_ip2);
    //printf("the rout ip is:%s\n",rout_ip2);
    //net_ip1.s_addr=temp2&0x00FFFFFF;



    unsigned int net_ip=temp2&0x00FFFFFF;
    int i, j;
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout <<"+++++k++++"<<k<<"**************"<<a4<< endl;
    for(i=0;i<a4;i++)
    {

        tableWidget->setRowCount(a4+1+k);
        tableWidget->setColumnCount(3);
        tableWidget->setSpan(0, 1, 1, 3);
        tableWidget->setItem(k,0,new QTableWidgetItem(a2));
        char ip_b[20];
        strcpy(ip_b, a2.toStdString().c_str());
        strcpy(value[k].table1,ip_b);
        //strcpy(value[i+k].table1,a2.toStdString().c_str());


        struct in_addr tmp;
        tmp.s_addr=net_ip;
        //QTextStream cout(stdout, QIODevice::WriteOnly);
       // cout <<"++++ip+++++"<<inet_ntoa(tmp)<< endl;
        printf("====a4 %d ",a4);
        unsigned int iptmp1=htonl(net_ip)+i+a5;
        unsigned int iptmp2=htonl(iptmp1);
        struct in_addr ip_add;
        ip_add.s_addr=iptmp2;
        char ip_buf[20];
        sprintf(ip_buf,"%s",inet_ntoa(ip_add));
        printf("the ip is:%s\n",ip_buf);

        //strcpy(value[i].table1,ip_buf);

        /*if(i == 0)
            {

                tableWidget->setSpan(0, 1, 1, 3);
                tableWidget->setItem(0,0,new QTableWidgetItem(a2));
                strcpy(value[i].table1,a2.toStdString().c_str());///this route addr
                printf("=====%d\n", i);
            }*/
        //else
        // {
         QTableWidgetItem *newItem =new  QTableWidgetItem();
         newItem->setTextAlignment(Qt::AlignRight);
            //strcpy(value[i+1+k].table1,ip_buf);

          QTableWidgetItem *newItem2 =new  QTableWidgetItem(ip_buf);

           newItem2->setTextAlignment(Qt::AlignRight);

        QTableWidgetItem *c = new QTableWidgetItem();
         c->setCheckState(Qt::Unchecked);
         c->setTextAlignment(Qt::AlignRight);

         QTableWidgetItem *b = new QTableWidgetItem();
          b->setCheckState(Qt::Unchecked);
          b->setTextAlignment(Qt::AlignRight);

        tableWidget->setItem(i+1+k,1,newItem);
        tableWidget->setItem(i+k+1,0,newItem2);
        strcpy(value[i+1+k].table1,ip_buf);
        //tableWidget->setItem(i+1+k,2,b);
        tableWidget->setItem(i+1+k,2,c);
        //value[i+1+k].table3=b
        printf("===%d\n", i);
    }
    k=a4+1+k;
    sprintf(net_buf,"%s",inet_ntoa(net_ip1));
    printf("the k is:%d\n",k);
    for(int s=0;s<=k;s++)
        printf("the ip is:%s\n",value[s].table1);
    for(int d=0;d<np;d++)
        {
        int l=n_buf[d];
        printf("the np is:%d**ip**%s\n",l,value[l].table1);
        }

}



void  FuncUpdatePage::server(int row, int col)
{
    if(col == 1)
    {

    char c_port[20];
    QString a = (tableWidget->item(row,col))->text() ;
    strcpy(c_port, a.toStdString().c_str());
    strcpy(value[row].table2, c_port);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout <<  value[row].table2 << endl;
    cout <<"row is:"<<row<<"col is:"<< col << endl;
    }
}
void FuncUpdatePage::changeTest(int row, int col)
 {
    if(tableWidget ->item(row, col)->checkState() == Qt::Checked)
     {
        value[row].table4 = 1;
           /* QTextStream cout(stdout, QIODevice::WriteOnly);
                      cout <<  value[row].table4 << endl;
                      cout <<"4--- " << row << " " << col <<endl;
                     cout<<"==============="<<row<<endl;*/
     }

 }
void FuncUpdatePage::start_route()
{
    int n_ip=k;
    FILE *fp;
    fp=fopen("route.conf","wr+");
    char route[10]="route ";
    char entry[50]="route entry ";
    strcat(entry,Localroute);
    fputs(entry,fp);
    fputs("\n",fp);
    char route1[100];
    strcpy(route1,route);
    strcat(route1,Localroute);
    strcat(route1," add net ");

    for(int i=0;i<np;i++)
    {
        int mem=n_buf[i];
        strcpy(routA_addr[i],value[mem].table1);

        printf("----------the ip is:%s\n",routA_addr[i]);

        unsigned int rout_addr=inet_addr(value[mem].table1);
        struct in_addr ip_addr;
        ip_addr.s_addr=rout_addr&0x00FFFFFF;
        char c_ip[25];
        sprintf(c_ip,"%s",inet_ntoa(ip_addr));
        strcat(c_ip,"/24 ");
        char add_r[100];
        strcpy(add_r,route1);
        strcat(add_r,c_ip);
        strcat(add_r,value[mem].table1);
        fputs(add_r,fp);
        fputs("\n",fp);

        char rt[100]="route ";
        strcat(rt,value[mem].table1);
        strcat(rt," link ");
        strcat(rt,c_ip);
        fputs(rt,fp);
        fputs("\n\n\n",fp);

        char rout_modl[100]="create ";
        char r_name[10]=" name";
        char r_n[5];
        sprintf(r_n,"%d ",i);
        strcat(r_name,r_n);
        strcat(rout_modl,r_name);
        fputs(rout_modl,fp);
        fputs("\n",fp);
        char set_r[100]="set ";
        strcat(set_r,r_name);
        char tcp_d[30]="default tcp action reset\n";
        strcat(set_r,tcp_d);
        fputs(set_r,fp);

        char sys[100]="set ";
        strcat(sys,r_name);
        char str[100];
        strcpy(str,sys);
        //strcat(str,tcp_d);
        //fputs(sys,fp);
        strcat(str," personality ");
        char route_type[100]=" \"Alcatel 1000 DSL Router\"\n";
        strcat(str,route_type);
        fputs(str,fp);

        char r_add[100]="add ";
        strcat(r_add,r_name);
        strcat(r_add,"tcp port 23 open\n");
        fputs(r_add,fp);
        char r_bind[100]="bind ";
        strcat(r_bind,value[mem].table1);
        strcat(r_bind,r_name);
        fputs(r_bind,fp);
        fputs("\n\n\n",fp);

       }
        for(int j=0;j<n_ip;j++)
        {
            int u=5;
           switch(j)
           {
           case 0 :break;
           case 5 :break;
           default :
           // int l;
           // printf("the np is:%d\n",np);
           // for(l=0;l<np;l++)
               //printf("$$$$$n_buf is:%d\n",n_buf[l]);
           // if(n_buf[l]!=j)
            //{
           //////为每一个ip 地址创建模板；
           char name[30]="route";
           char n[10];
           sprintf(n,"%d",j);
           strcat(name,n);
           char create[100]="create ";
           strcat(create,name);
           fputs(create,fp);
           fputs("\n",fp);

           //////
           char set[30]=" set ";
           strcat(set,name);
           char r_buf[100];
           if(value[j].table4==1)
           {
               char tcp[100]=" default tcp action block\n";
               char udp[100]=" default udp action block\n";
               char icmp[100]=" default icmp action block\n\n";
               strcpy(r_buf,set);
               strcat(r_buf,tcp);
               fputs(r_buf,fp);

               strcpy(r_buf,set);
               strcat(r_buf,udp);
               fputs(r_buf,fp);

               strcpy(r_buf,set);
               strcat(r_buf,icmp);
               fputs(r_buf,fp);
           }
           else
           {
               char tcp[100]=" default tcp action reset\n";
               char udp[100]=" default udp action block\n";
               char icmp[100]=" default icmp action open\n\n";
               strcpy(r_buf,set);
               strcat(r_buf,tcp);
               fputs(r_buf,fp);

               strcpy(r_buf,set);
               strcat(r_buf,udp);
               fputs(r_buf,fp);

               strcpy(r_buf,set);
               strcat(r_buf,icmp);
               fputs(r_buf,fp);
           }
           /////端口号模拟
           int len=strlen(value[j].table2);
           char p_buf[100];
           strcpy(p_buf,value[j].table2);
           //QTextStream cout(stdout, QIODevice::WriteOnly);
           //cout <<value[j].table2<<"this yuan port"<<endl;
           //cout <<p_buf<< " this port"<< endl;
           strcat(p_buf,",");
           int t;
           int k=0;
           for(t=0;t<=len;t++)
              {
                  if(p_buf[t]==',')
                  {
                      char port[6];
                      char add[100]="add ";
                      strcat(add,name);
                      strcat(add," tcp port ");
                      //struct p_port port_add;
                      strncpy(port,p_buf+k,t-k);
                      int m_port=atoi(port);
                      //printf("the port is:%d\n",m_port);

                      char p_set[100];
                      char open_port[6];
                      switch(m_port)
                      {
                          case 80:
                             strcpy(p_set,add);
                             strcat(p_set," 80 \"sh /usr/local/share/honeyd/suse7.0/apache.sh\"\n");
                             fputs(p_set,fp);
                             break;
                          case 21:
                             strcpy(p_set,add);
                             strcat(p_set," 21 \"sh /usr/local/share/honeyd/linux/ftp.sh\"\n");
                             fputs(p_set,fp);
                             break;
                         case 110:
                             strcpy(p_set,add);
                             strcat(p_set," 110 \"sh /usr/local/share/honeyd/linux/qpop.sh\"\n");
                             fputs(p_set,fp);
                             break;
                         case 25:
                             strcpy(p_set,add);
                             strcat(p_set," 25  \"sh /usr/local/share/honeyd/linux/smtp.sh\"\n");
                             fputs(p_set,fp);
                             break;
                         case 23:
                             strcpy(p_set,add);
                             strcat(p_set," 23  \"sh /usr/local/share/honeyd/suse7.0/telnetd.sh\"\n");
                             fputs(p_set,fp);
                             break;
                         case 22:
                             strcpy(p_set,add);
                             strcat(p_set," 22  \"sh /usr/local/share/honeyd/suse7.0/ssh.sh\"\n");
                             fputs(p_set,fp);
                             break;
                         case 135:
                             strcpy(p_set,add);
                             strcat(p_set," 135 \"sh /usr/local/share/honeyd/suse7.0/rpc.sh\"\n");
                             fputs(p_set,fp);
                             break;
                      default:
                          sprintf(open_port,"%d ",m_port);
                          strcpy(p_set,add);
                          strcat(p_set,open_port);
                          strcat(p_set,"open\n");
                          fputs(p_set,fp);
                      }
                      k=t+1;
                   }
              }
           /////bind ip 地址；
           char bind[100]="bind ";
           strcat(bind,value[j].table1);
           strcat(bind," ");
           strcat(bind,name);
           fputs(bind,fp);
           fputs("\n\n\n",fp);
        }

        }
        fclose(fp);
        threadC.start();
  }
    //////

void FuncUpdatePage::stop_route()
{
    remove("./route.conf");
    threadC.stop();
}
