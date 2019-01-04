#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    int xpos = 30;

    for(int i = 0 ; i < 3 ; i++, xpos += 110)
    {
        dial[i] = new QDial(this);
        dial[i]->setRange(0, 100);
        dial[i]->setGeometry(xpos, 30, 100, 100);
    }

    dial[0]->setNotchesVisible(true);

    connect(dial[0], SIGNAL(valueChanged(int)),
                     this,
                     SLOT(changedData()));
}

void Widget::changedData()
{
    qDebug("QDial 1 value : %d", dial[0]->value());
}

Widget::~Widget()
{

}
