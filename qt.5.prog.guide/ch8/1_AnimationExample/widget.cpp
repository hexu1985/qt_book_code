#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(300, 200);

    QPushButton *btn = new QPushButton("Button", this);
    btn->setGeometry(10, 10, 100, 30);

    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(btn, "geometry", this);

    animation->setDuration(3000); // 3초(단위 밀리세컨드)
    animation->setStartValue(QRect(10, 10, 100, 30)); // 시작 좌표
    animation->setEndValue(QRect(200, 150, 100, 30)); // 끝나는 좌표

    animation->start();
}

Widget::~Widget()
{

}
