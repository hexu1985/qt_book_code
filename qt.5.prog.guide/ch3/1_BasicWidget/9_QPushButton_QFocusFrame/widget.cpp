#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QPushButton");

    QPushButton *btn[3];

    int ypos = 30;

    for(int i = 0 ; i < 3 ; i++)
    {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i), this);
        btn[i]->setGeometry(10, ypos, 300, 40);

        ypos += 50;
    }

    connect(btn[0], SIGNAL(clicked()), this, SLOT(btn_click()));
    connect(btn[0], SIGNAL(pressed()), this, SLOT(btn_pressed()));
    connect(btn[0], SIGNAL(released()), this, SLOT(btn_released()));


    QFocusFrame *btn_frame = new QFocusFrame(this);

    btn_frame->setWidget(btn[0]);
    btn_frame->setAutoFillBackground(true);


}

void Widget::btn_click()
{
    qDebug("Button Click");
}

void Widget::btn_pressed()
{
    qDebug("Button Pressed");
}

void Widget::btn_released()
{
    qDebug("Button Relased");
}

Widget::~Widget()
{
}

