#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QImage image(":/resources/qtblog.png");

//    QPainter painter(this);
//    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
//    painter.drawRect(0, 0, 100, 100);

//    QTransform transform;
//    transform.translate(50, 50);
//    transform.rotate(45);
//    transform.scale(0.5, 0.5);

//    painter.setTransform(transform);
//    painter.drawImage(0, 0, image);

    //------

    QPainter painter(this);
    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
    painter.drawRect(0, 0, 100, 100);

    QTransform transform;
    transform.translate(50, 50);
    transform.rotate(70, Qt::YAxis);

    painter.setTransform(transform);
    painter.drawImage(0, 0, image);


    painter.end();
}

Widget::~Widget()
{

}
