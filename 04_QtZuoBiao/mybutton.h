#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyBUtton : public   QPushButton
{
    Q_OBJECT
public:
    explicit MyBUtton(QWidget *parent = nullptr);
    ~MyBUtton();
signals:

public slots:
};

#endif // MYBUTTON_H
