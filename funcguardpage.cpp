#include "funcguardpage.h"
#include <funcguardpage.h>
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
#include "threadcz.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#include <qvalidator.h>


FuncGuardPage::FuncGuardPage(QWidget *parent)
    :QWidget(parent)
{
        setObjectName(tr("guardPage"));
        this->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(QPixmap(":/images/1fine1.png")));
        this->setPalette(palette);
        //struct send value[200];



        second();
}


void FuncGuardPage::second()
{
    //左
    QGroupBox *updateGroup = new QGroupBox(tr("虚拟主机"));
    QStringList labels;
    labels << tr("虚拟IP地址") << tr("虚拟服务") << tr("系统类型") << tr("是否静默");
    tableWidget = new QTableWidget;
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels(labels);
    //tableWidget->horizontalHeader()-> setResizeMode(QHeaderView::Stretch);

    QLabel *numberLabel1 = new QLabel;
    numberLabel1->setText(QObject::tr("虚拟主机数(个)"));
    numberLine1 = new QLineEdit("25");

    QLabel *numberLabel2 = new QLabel;
    numberLabel2->setText(QObject::tr("IP跳变数(个)"));
    numberLine2 = new QLineEdit("15");

    makeButton = new QPushButton(tr("设置"));
    xnButton = new QPushButton(tr("显示地址"));
    xnfwButton = new QPushButton(tr("启动虚假主机"));

    connect(makeButton,SIGNAL(clicked()),this,SLOT(sendButton()));
    connect(tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(changeTest(int, int)));
    connect(tableWidget, SIGNAL(cellChanged(int,int)), this, SLOT(server(int, int)));

    connect(xnButton,SIGNAL(clicked()),this,SLOT(xnfw()));
    connect(xnfwButton,SIGNAL(clicked()),this,SLOT(tc()));



    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(tableWidget,0,0,1,5);
    leftLayout->addWidget(numberLabel1,1,0);

    leftLayout->addWidget(numberLine1,1,1);
    numberLine1->setFixedSize(50,30);
    leftLayout->addWidget(numberLabel2,1,2);
    leftLayout->addWidget(numberLine2,1,3);
    numberLine2->setFixedSize(50,30);
    QVBoxLayout *updateLayout = new QVBoxLayout;

    updateLayout->addLayout(leftLayout);
    updateGroup->setLayout(updateLayout);

    //右上
    QGroupBox *xyGroup = new QGroupBox(tr("协议混淆"));

//        ksButton = new QPushButton(tr("开始协议栈混淆"));
//        tzButton = new QPushButton(tr("停止协议栈混淆"));
//        tzButton->setEnabled(false);

//        connect(ksButton,SIGNAL(clicked()),this,SLOT(startq()));
//        connect(tzButton,SIGNAL(clicked()),this,SLOT(stopinsmod2()));

        w = new QCheckBox;
        QLabel *wi = new QLabel(tr("Linux 操作系统"));
        l = new QCheckBox;
        QLabel *li= new QLabel(tr("Windows xp操作系统"));
        m = new QCheckBox;
        QLabel *ma = new QLabel(tr("IBM 操作系统"));

        connect(w, SIGNAL(stateChanged(int)), this, SLOT(ww(int)));
        connect(l, SIGNAL(stateChanged(int)), this, SLOT(ww(int)));
        connect(m, SIGNAL(stateChanged(int)), this, SLOT(ww(int)));



        r = new QCheckBox;
        QLabel *ri= new QLabel(tr("Apache"));
        b = new QCheckBox;
        QLabel *ba = new QLabel(tr("iis"));

        connect(r, SIGNAL(stateChanged(int)), this, SLOT(yy(int)));
        connect(b, SIGNAL(stateChanged(int)), this, SLOT(yy(int)));

        QHBoxLayout *z1= new QHBoxLayout;
        z1->addWidget(w);

        z1->addWidget(wi);

        QHBoxLayout *z2= new QHBoxLayout;
        z2->addWidget(l);
        z2->addWidget(li);

        QHBoxLayout *z3= new QHBoxLayout;
        z3->addWidget(m);
        z3->addWidget(ma);

        QHBoxLayout *z4= new QHBoxLayout;
        z4->addWidget(r);
        z4->addWidget(ri);


        QHBoxLayout *z5= new QHBoxLayout;
        z5->addWidget(b);
        z5->addWidget(ba);

        QVBoxLayout *z6 = new QVBoxLayout;
        z6->addLayout(z1);
        z6->addLayout(z2);
        z6->addLayout(z3);


        QVBoxLayout *z7 = new QVBoxLayout;
        z7->addLayout(z4);
        z7->addLayout(z5);


//        QVBoxLayout *z5 = new QVBoxLayout;
//        z5->addWidget(ksButton);
//        z5->addWidget(tzButton);

        QHBoxLayout *z88= new QHBoxLayout;
        z88->addLayout(z6);
        z88->addSpacing(100);
        z88->addLayout(z7);

        ksButton = new QPushButton(tr("开始协议混淆"));
        tzButton = new QPushButton(tr("停止混淆"));
        czButton = new QPushButton(tr("开始操作系统混淆"));

        connect(ksButton,SIGNAL(clicked()),this,SLOT(startxy()));
        connect(czButton,SIGNAL(clicked()),this,SLOT(startcz()));
        connect(tzButton,SIGNAL(clicked()),this,SLOT(stopinsmod2()));


         QHBoxLayout *z99 = new QHBoxLayout;
         z99->addSpacing(20);
         z99->addWidget(czButton);
         z99->addSpacing(20);
         z99->addWidget(ksButton);
         z99->addSpacing(20);
         z99->addWidget(tzButton);

        QVBoxLayout *z9 = new QVBoxLayout;


        z9->addLayout(z88);
        z9->addLayout(z99);
        xyGroup->setLayout(z9);

    //右下
    QGroupBox *packageGroup = new QGroupBox(tr("本机动态IP跳变"));

    QStringList label;
    label << tr("可跳变IP") << tr("状态");
    tableWidget2 = new QTableWidget(this);
    tableWidget2->setColumnCount(2);
    tableWidget2->setHorizontalHeaderLabels(label);
    tableWidget2->horizontalHeader()-> setResizeMode(QHeaderView::Stretch);

    QLabel *numberLabel3 = new QLabel;
    numberLabel3->setText(QObject::tr("跳变时间间隔(s)"));
    numberLine3 = new QLineEdit("1200");
    numberLine3->setFixedSize(50,30);
    QLabel *numberLabel4 = new QLabel;
    numberLabel4->setText(QObject::tr("是否虚假流量(0或1)"));
    numberLine4 = new QLineEdit("0");
    numberLine4->setFixedSize(50,30);

    selectButton = new QPushButton(tr("显示跳变地址"));
    stopButton = new QPushButton(tr("停止"));
    connect(selectButton,SIGNAL(clicked()),this,SLOT(controlButton()));

    QHBoxLayout *zh = new QHBoxLayout;
    zh->addSpacing(20);
    zh->addWidget(makeButton);
    zh->addSpacing(30);
    zh->addWidget(xnButton);
    zh->addSpacing(30);
    zh->addWidget(xnfwButton);
    zh->addSpacing(100);
    zh->addWidget(selectButton);
    zh->addSpacing(50);
    zh->addWidget(stopButton);
    zh->addSpacing(70);


    QGridLayout *add = new QGridLayout;
    add->addWidget(tableWidget2,0,4,1,5);
    add->addWidget(numberLabel3,1,4);
    add->addWidget(numberLine3,1,5);
    add->addWidget(numberLabel4,1,6);
    add->addWidget(numberLine4,1,7);
    connect(stopButton,SIGNAL(clicked()),this,SLOT(stopThread()));

    QVBoxLayout *packageLayout = new QVBoxLayout;
    packageLayout->addLayout(add);
    packageGroup->setLayout(packageLayout);


    QVBoxLayout *z8 = new QVBoxLayout;
    z8->addWidget(xyGroup);
    z8->addWidget(packageGroup);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(updateGroup);

    mainLayout->addLayout(z8);

    QVBoxLayout *mainLayout1 = new QVBoxLayout;
    mainLayout1->addLayout(mainLayout);
    mainLayout1->addLayout(zh);
    //mainLayout1->addSpacing(12);

    //mainLayout->addStretch(1);
    setLayout(mainLayout1);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(get_interface()));
    class QValidator *validator=new QIntValidator(0,9999,this);

    numberLine1->setValidator(validator);
    if(numberLine1->text().toInt() == NULL)
    {
        //selectButton->setEnabled(false);
        stopButton->setEnabled(false);
        //xnButton->setEnabled(false);
        xnfwButton->setEnabled(false);
    }
    int i;
    for(i=0;i<a1;i++);
    {

        //strcpy(value[i].table2,"21");///初始默认端口是1,21
        value[i].table3=0;//0表示windows,1表示linux 2表示mac
        value[i].table4=0;//0是不静默
    }
    //m1=10;
    //printf("the m is:%d\n",m1);
}
void  FuncGuardPage::xnfw()
 {
        QFile file2( "./host.txt" );
        if ( file2.open(QFile::ReadOnly) ) {
            QTextStream stream2(&file2);
            QString line2;


            int cout2 = 0;
            while (!stream2.atEnd()) {

                line2 = stream2.readLine(); // 2?¡ãš¹š€??¡ã/n?¡ÀŠÌ?š°?DD??¡À?
                //line2 = stream.readLine(); // 2?¡ãš¹š€??¡ã/n?¡ÀŠÌ?š°?DD??¡À?
//                QTextStream cout(stdout, QIODevice::WriteOnly);
//                                       cout<<"line is=========="<<line2 <<" ";
//                checkBox = new QTableWidgetItem();
//                checkBox->setCheckState(Qt::Unchecked);

 //               QComboBox *comBox = new QComboBox();
 //               comBox->addItem("Y");
 //               comBox->addItem("N");

                QComboBox *b = new QComboBox();
                QTableWidgetItem *newItem =new  QTableWidgetItem();




                QTableWidgetItem *c = new QTableWidgetItem();
                 c->setCheckState(Qt::Unchecked);

                    b->addItem("Windows xp");
                    b->addItem("Linux 2.4.7");
                    b->addItem("Windows NT");
                    b->addItem("IBM AIX 4.2");
                    b->addItem("Apple Mac OS");

                     char ip_b[20];
                     strcpy(ip_b, line2.toStdString().c_str());
                     strcpy(value[cout2].table1, ip_b);
                tableWidget->setRowCount((numberLine1->text()).toInt());
                tableWidget->setColumnCount(4);

                tableWidget->setItem(cout2,1,newItem);
//                 printf("====%s", value[cout2].table2);
      //           newItem->setText(value[cout2].table2);
                tableWidget->setItem(cout2,0,new QTableWidgetItem(line2));
                tableWidget->setCellWidget(cout2,2,b);

                tableWidget->setItem(cout2,3,c);
                connect(b, SIGNAL(currentIndexChanged(int)),this, SLOT(changed(int)));

//                tableWidget->setItem(cout2,1,checkBox);

                // tableWidget->setCellWidget(0,2,comBox);
               // tableWidget2->setItem(cout,1,new QTableWidgetItem(line2));
                cout2++;
 //                        cout<<""<<line;
            }
                file2.close();
           }

 }

void FuncGuardPage::tc()
{
    FILE*fp;
    int j,buf[255];
    srand((unsigned long)time(0));
       for(int t=0;t<a1;t++)
           buf[t]=(rand()%10);
       int port[]={21,80,53,445,3389,139,2049,110,81,13};
    for(int d=0;d<a1;d++)
    {
        int n_port=buf[d];
        char str_port[10];
        printf("the port is :%d\n",port[n_port]);
        sprintf(str_port,"%d",port[n_port]);
        printf("the port is :%sthe len is:%d\n",str_port,strlen(str_port));
        if(strcmp(value[d].table2,"")!=1)
            strcpy(value[d].table2,str_port);
        printf("++++++++++++++++++++++++the %s+++++++++++++\n",value[d].table2);
        tableWidget->item(d,1)->setText(value[d].table2);
    }

    fp=fopen("syshost.conf","wr+");
    for(j=0;j<a1;j++)
    {
        unsigned int temp=inet_addr(value[j].table1);

        int num=temp>>24;
        char name[10]=" name";
        char buf[10];
        sprintf(buf,"%d ",num);
        strcat(name ,buf);

        char create[20]="create ";
        char set[20]="set ";
        char per[30]=" personality ";
        char tcp[100]=" default tcp action ";
        char udp[100]=" default udp action ";
        char icmp[100]=" default icmp action ";
        strcat(create,name);
        strcat(set,name);
        fputs(create,fp);
        fputs("\n",fp);
        char s_buf[100];
        strcpy(s_buf,set);
        strcat(s_buf,per);
        char systype[100];
        switch(value[j].table3)
        {////////////////////////////Microsoft Windows XP SP1
        case 0:  strcpy(systype,"\"Microsoft Windows XP SP1\"\n");
                 break;
        case 1:  strcpy(systype,"\"Linux 2.4.7 (X86)\"\n");
                 break;
        case 2:  strcpy(systype,"\"Microsoft Windows NT 4.0 SP3\"\n");
                 break;
        case 3:  strcpy(systype,"\"IBM AIX 4.2\"\n");
                 break;
        case 4:  strcpy(systype,"\"Apple Mac OS 9.2.2\"\n");
        default :break;
        }
        strcat(s_buf,systype);///
        fputs(s_buf,fp);
        if(value[j].table4==1)
        {
            strcat(tcp,"block\n");
            strcat(udp,"block\n");
            strcat(icmp,"block\n");
        }
        else
        {
            strcat(tcp,"reset\n");
            strcat(udp,"block\n");
            strcat(icmp,"open\n");
        }



        strcpy(s_buf,set);
        strcat(s_buf,tcp);
        fputs(s_buf,fp);

        strcpy(s_buf,set);
        strcat(s_buf,udp);
        fputs(s_buf,fp);

        strcpy(s_buf,set);
        strcat(s_buf,icmp);
        fputs(s_buf,fp);


        int len=strlen(value[j].table2);
        char p_buf[100];
        strcpy(p_buf,value[j].table2);
        QTextStream cout(stdout, QIODevice::WriteOnly);
        cout <<value[j].table2<<"this yuan port"<<endl;
        cout <<p_buf<< " this port"<< endl;
        strcat(p_buf,",");
        int i;
        int k=0;
        for(i=0;i<=len;i++)
           {
               //printf("the str is:%c",p_buf[i]);
               //printf("the zifu si:%c\n",'\0');
               if(p_buf[i]==',')
               {
                   char port[6];
                   char add[100]="add ";
                   strcat(add,name);
                   strcat(add,"tcp port ");
                   //struct p_port port_add;
                   strncpy(port,p_buf+k,i-k);
                   //printf("the i is:%d,the port is:%s\n",i,port);
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

                   k=i+1;
                }
           }
        strcpy(s_buf,set);
        strcat(s_buf," ethernet ");
        //srand((unsigned long)time(0));
        int temp1=rand()%254;
        int temp2=rand()%254;
        int temp3=rand()%254;
        int temp4=rand()%254;
        int temp5=rand()%254;
        int temp6=rand()%254;
        char mac[40];
        sprintf(mac," \"%02x:%02x:%02x:%02x:%02x:%02x\"\n",temp1,temp2,temp3,temp4,temp5,temp6);
        strcat(s_buf,mac);
        fputs(s_buf,fp);

        ///////bind ip
        char bind[100]="bind ";
        strcat(bind,value[j].table1);
        strcat(bind,name);
        fputs(bind,fp);
        fputs("\n\n\n",fp);
    }
    fclose(fp);
    threadB.start();
}

void FuncGuardPage::fileadd(char str[])
 {
    FILE *fp;
    char ch;
    fp=fopen("windows.conf","at+");
    fputs(str,fp);
    fputs("\n",fp);
    rewind(fp);
    printf("\n");
    fclose(fp);
}
int *FuncGuardPage::ran(int buffer[], int length)
{
    int buf[length];
    srand((unsigned long)time(0));
    for(int i = 0; i < length; i++)
    {
        int temp=rand()%254;
        if(temp!=0)
        buf[i] =temp;
    }
    for(int j=0;j<length;j++)
    {
      int n=buf[j];
      for(int k=j+1;k<length;k++)
      {
          if(n==buf[k])
            buf[k]=rand()%254;
          else
            continue;
      }
      buffer[j]=n;
    }
    return buffer;
}


void FuncGuardPage::changed(int i)
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    //QComboBox* combo=(QComboBox*)tableWidget->cellWidget(0, 2);

     value[row2].table3 = i;
      cout << value[row2].table3 << endl;


      cout << "3---" << row2 <<endl;
}

void  FuncGuardPage::server(int row, int col)
{
    if(col == 1)
    {
    row2 = row;
    char c_port[20];
    QString a = (tableWidget->item(row,col))->text() ;
    strcpy(c_port, a.toStdString().c_str());
    strcpy(value[row2].table2, c_port);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout <<  value[row2].table2 << endl;
    cout << "sever-row2---+++---" << row2 <<"row is:"<<row<<"col is:"<< col << endl;
    }
}
void FuncGuardPage::changeTest(int row, int col)
 {
    if(tableWidget ->item(row, col)->checkState() == Qt::Checked)
     {
        value[row2].table4 = 1;
            QTextStream cout(stdout, QIODevice::WriteOnly);
                      cout <<  value[row2].table4 << endl;
                      cout <<"4--- " << row << " " << col <<endl;
                      cout<<"==============="<<row2<<endl;

     }

 }

void FuncGuardPage::sendButton()
{
            a1 = numberLine1->text().toInt();
            a2 = numberLine2->text().toInt();
            a3 = numberLine3->text().toInt();
            a4 = numberLine4->text().toInt();

        threadA.a1=a1;
        threadA.a2=a2;
        threadA.a3=a3;
        threadA.a4=a4;
        threadA.start();
//        makeButton->setText(tr("Stop B"));
//    }
        selectButton->setEnabled(true);
        stopButton->setEnabled(true);
        xnButton->setEnabled(true);
        xnfwButton->setEnabled(true);

}

void FuncGuardPage::controlButton()
{

    if (timer->isActive()) {
        timer->stop();
        selectButton->setText(tr("开始更新"));
    } else {
        timer->start();
        selectButton->setText(tr("停止更新"));
    }

}

void FuncGuardPage::get_interface()
{
    timer->start(200);
             QFile file( "./chg.txt" );
                if ( file.open(QFile::ReadOnly) ) {
                    QTextStream stream(&file);
                    QString line1;
                    QString line2;
                    int count = 0;
                    while (!stream.atEnd()) {
//                        QTextStream cout(stdout, QIODevice::WriteOnly);
//                                               cout<<"line is=========="<<line1 <<" ";
                        line1 = stream.readLine(); // 2?¡ãš¹š€??¡ã/n?¡ÀŠÌ?š°?DD??¡À?
                        line2 = stream.readLine(); // 2?¡ãš¹š€??¡ã/n?¡ÀŠÌ?š°?DD??¡À?
                        tableWidget2->setRowCount((numberLine2->text()).toInt()+1);
                        tableWidget2->setColumnCount(2);
                        tableWidget2->setItem(count,0,new QTableWidgetItem(line1));
                        tableWidget2->setItem(count,1,new QTableWidgetItem(line2));

//                        QTextStream cout(stdout, QIODevice::WriteOnly);
//                        cout<<"line is"<<line1 <<" ";
//                        cout<< count <<endl;
                        count++;
                    }
                    file.close();
           }
}
void FuncGuardPage::stopThread()
{
    selectButton->setEnabled(false);
    stopButton->setEnabled(false);
    xnButton->setEnabled(false);
    xnfwButton->setEnabled(false);
    threadA.stop();
    if(threadA.isRunning())
    {
        threadA.terminate();
    }
    if (timer->isActive()) {
        timer->stop();
        selectButton->setText(tr("显示"));
    }
    char buf2[] = "pkill honeyd";
    system(buf2);
}
void FuncGuardPage::startxy()
{
    threadD.flag = 1;
    threadD.start();

    //ksButton->setEnabled(false);
    //zButton->setEnabled(true);
  //  QMessageBox::information(this,tr("协议混淆"),tr("协议混淆成功。"));
}


void FuncGuardPage::startcz()
{
    threadD.flag = 0;
    threadD.start();
   //threadC.start();
}

void FuncGuardPage::stopinsmod2()
{

//    threadC.stop();
//    if(threadC.isRunning())
//    {
//            threadC.terminate();
//     }
    threadD.stop();

    threadD.terminate();

}

void FuncGuardPage::ww(int row)
{
   int i = 0;
    if(w->isChecked())
        i = 1;
    else if(l->isChecked())
        i = 2;
    else if(m->isChecked())
        i = 3;
    threadD.c1 = i;
}

void FuncGuardPage::yy(int row)
{
    int j = 0;
    if(r->isChecked())
        j = 0;
    else if(b->isChecked())
        j = 1;
    threadD.c2 = j;
}

