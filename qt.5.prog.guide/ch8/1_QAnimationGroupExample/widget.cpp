#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    resize(320, 270);
    QPushButton *btn1 = new QPushButton("First", this);
    btn1->setGeometry(10, 10, 100, 30);

    QPushButton *btn2 = new QPushButton("Second", this);
    btn2->setGeometry(10, 45, 100, 30);

    anim1 = new QPropertyAnimation(btn1, "geometry");
    anim1->setDuration(2000); // 2초(단위 밀리세컨드)
    anim1->setStartValue(QRect(10, 10, 100, 30)); // 시작 좌표
    anim1->setEndValue(QRect(200, 150, 100, 30)); // 끝나는 좌표

    anim2 = new QPropertyAnimation(btn2, "geometry");
    anim2->setDuration(2000); // 2초(단위 밀리세컨드)
    anim2->setStartValue(QRect(10, 45, 100, 30)); // 시작 좌표
    anim2->setEndValue(QRect(200, 195, 100, 30)); // 끝나는 좌표

    sGroup = new QSequentialAnimationGroup; // Sequential Group
    sGroup->addAnimation(anim1);
    sGroup->addAnimation(anim2);

    //pGroup = new QParallelAnimationGroup; // Parallel Group
    //pGroup->addAnimation(anim1);
    //pGroup->addAnimation(anim2);

    connect(btn1, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(btn_clicked()));
}

void Widget::btn_clicked()
{
    sGroup->start(QPropertyAnimation::DeleteWhenStopped);
    //pGroup->start(QPropertyAnimation::DeleteWhenStopped);
}

Widget::~Widget()
{

}
