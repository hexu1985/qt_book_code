#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    resize(300, 220);

    QPushButton *btn = new QPushButton("Button", this);
    btn->setGeometry(10, 10, 100, 30);


    animation = new QPropertyAnimation(btn, "geometry", this);
    animation->setDuration(2000); // 2 secs
    animation->setStartValue(QRect(10, 10, 100, 30)); // start
    animation->setEndValue(QRect(200, 150, 100, 30)); // end

    QEasingCurve easing(QEasingCurve::InElastic);
    for(qreal t = 0.0; t < 1.0; t+=0.1)
    {
        qDebug() << "Effective progress" << t << " is"
                 << easing.valueForProgress(t);
    }
    animation->setEasingCurve(easing);
    connect(btn, SIGNAL(clicked()), this, SLOT(btn_clicked()));
}

void Widget::btn_clicked()
{
    animation->start();
}

Widget::~Widget()
{

}
