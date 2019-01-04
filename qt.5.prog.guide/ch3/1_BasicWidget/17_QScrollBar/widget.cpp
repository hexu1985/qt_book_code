#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    int xpos = 10;
    int ypos = 50;
    for(int i = 0 ; i < 3 ; i++)
    {
        vscrollbar[i] = new QScrollBar(Qt::Vertical, this);
        vscrollbar[i]->setRange(0, 100);
        vscrollbar[i]->setGeometry(xpos, 30, 20, 200);

        lbl[i] = new QLabel(QString("%1").arg(vscrollbar[i]->value()), this);
        lbl[i]->setGeometry(xpos + 2, 220, 30, 30);
        xpos += 50;

        hscrollbar[i] = new QScrollBar(Qt::Horizontal, this);
        hscrollbar[i]->setRange(0, 100);
        hscrollbar[i]->setGeometry(150, ypos, 200, 20);
        ypos += 30;
    }

    connect(vscrollbar[0], SIGNAL(valueChanged(int)), this,
                          SLOT(valueChanged1(int)));

    connect(vscrollbar[1], SIGNAL(valueChanged(int)), this,
                          SLOT(valueChanged2(int)));

    connect(vscrollbar[2], SIGNAL(valueChanged(int)), this,
                          SLOT(valueChanged3(int)));
}

void Widget::valueChanged1(int value)
{
    lbl[0]->setText(QString("%1").arg(value));
    hscrollbar[0]->setValue(vscrollbar[0]->value());
}

void Widget::valueChanged2(int value)
{
    lbl[1]->setText(QString("%1").arg(value));
    hscrollbar[1]->setValue(vscrollbar[1]->value());
}

void Widget::valueChanged3(int value)
{
    lbl[2]->setText(QString("%1").arg(value));
    hscrollbar[2]->setValue(vscrollbar[2]->value());
}

Widget::~Widget()
{

}
