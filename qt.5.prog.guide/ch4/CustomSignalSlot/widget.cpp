#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel("", this);
    lbl->setGeometry(10, 10, 100, 40);

    SignalSlot s1, s2;

    QObject::connect(&s1, SIGNAL(valueChanged(int)),
                     &s2, SLOT(setValue(int)));

    s1.setValue(50); // s1.value = 50, s2.value = 50

    lbl->setText(QString("%1").arg(s2.value()));
}

Widget::~Widget()
{

}

void SignalSlot::setValue(int value)
{
    m_value = value;
    emit valueChanged(m_value);
}
