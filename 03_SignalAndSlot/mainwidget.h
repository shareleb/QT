#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subwidget.h"  //子窗口头文件
#include<QString>
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:

    void mySlot();
    void qieHuan();
    void dealSub();
    void dealSlot(int,QString);
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    subWidget w;
};

#endif // MAINWIDGET_H
