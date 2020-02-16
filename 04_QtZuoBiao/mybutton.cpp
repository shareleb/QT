#include "mybutton.h"
#include<QDebug>
MyBUtton::MyBUtton(QWidget *parent) :QPushButton(parent)
{

}
MyBUtton::~MyBUtton()
{
    qDebug()<<"按钮被析构";
}
