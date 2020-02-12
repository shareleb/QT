#include "mainwidget.h"
#include<QPushButton>
#include<QDebug>  //打印
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{

     b1.setParent(this);
     b1.setText("close");
     b1.move(100,100);
     b2=new QPushButton(this);
     b2->setText("abc");

     //qt重要是信号与槽
     connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    /*
     * &b1  信号发出者，指针类型
     * &QPushButton::pressed  处理的信号     &发送者的类名：：信号名字
     * this   信号接受者
     * &MainWidget::close   槽函数  信号处理函数         &接收者的类型：：槽函数的名字
     *
     *
     */

     /*  自定义槽  ： 普通函数的用法。
      * QT5：  任意的成员函数，普通全局函数，静态函数
      * 槽函数需要和信号一致（参数,返回值）
      * 由于信号都是没有返回值，所以槽函数一定没有返回值。
      */
     connect(b2,&QPushButton::released,this,&MainWidget::mySlot);


     connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

       /*   信号： 短信
        * 槽函数：   接受短信的手机
        */

       setWindowTitle("老大");

        b3.setParent(this);
        b3.setText("切换到子窗口");
        b3.move(50,50);

        //w.show();
        connect(&b3,&QPushButton::released,this,&MainWidget::qieHuan);
//        //处理子窗口的信号
//         void (subWidget::*finSignal)()=&subWidget::mySignal;

//        connect(&w,finSignal,this,&MainWidget::dealSub);
//        void (subWidget::*testSignal)(int,QString)=&subWidget::mySignal;
//        connect(&w,testSignal,this,&MainWidget::dealSlot);

        //qt4信号连接
        //QT4槽函数必须要有slots: 关键字来修饰。

      //  SIGNAL  SLOT 将函数名字-》  字符串   不进行错误检查
       // Lambda表达式       匿名函数对象
        //项目文件  CONFIG+=c++11
    //	c++11增加的新特性
      //  QT配合信号一起使用，非常方便

        connect(&w,SIGNAL(mySignal()),this,SLOT(dealSub()));
        connect(&w,SIGNAL(mySignal(int,QString)),this,SLOT(dealSlot(int,QString)));

        QPushButton *b4=new QPushButton(this);
        b4->setText("Lambda表达式");
        b4->move(150,150);
        int a=10;
        connect(b4,&QPushButton::clicked,
                // =  把外部所有的局部变量、类中的所有成员以值传递方式。(只读方式传进来）    [] 的作用就是传参数进来。
                //This    类中所有成员以值传递方式

               // & ： 把外部所有局部变量   ，以引用方式传过来                  引用符号
                [=](bool isCheck) // mutable    //一般用=  因为构造函数使用后局部变量会释放，而槽函数还没执行呢  所有会出错
                 {
                   qDebug()<<isCheck;
                 }

                );
        if(a==11)
         {
        qDebug()<<a;
        }
       resize(400,400);

}


void MainWidget::mySlot()
{
    b2->setText("123");
}
void MainWidget::dealSlot(int A, QString str)
{
    //str.toUtf8() ->  字节数组  QByteArray
    //data()  ->   QByteArray ->char*
    qDebug()<<A<<str<<endl;
}

void MainWidget::dealSub()
{
    w.hide();
    this->show();

}
void MainWidget::qieHuan()
{
    //本窗口隐藏
    this->hide();  //隐藏
    //子窗口显示
    w.show();



}

MainWidget::~MainWidget()
{

}
