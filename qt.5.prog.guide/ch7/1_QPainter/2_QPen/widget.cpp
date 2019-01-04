#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin(this);

//    QPen pen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

//    painter.setPen(pen);
//    QRect rect1(10.0, 20.0, 80.0, 50);
//    painter.drawEllipse(rect1);

//    pen.setStyle(Qt::DashLine);
//    painter.setPen(pen);
//    QRect rect2(110.0, 20.0, 80.0, 50.0);
//    painter.drawEllipse(rect2);

//    pen.setStyle(Qt::DotLine);
//    painter.setPen(pen);
//    QRect rect3(210.0, 20.0, 80.0, 50.0);
//    painter.drawEllipse(rect3);

//    pen.setStyle(Qt::DashDotLine);
//    painter.setPen(pen);
//    QRect rect4(10.0, 100.0, 80.0, 50.0);
//    painter.drawEllipse(rect4);

//    pen.setStyle(Qt::DashDotDotLine);
//    painter.setPen(pen);
//    QRect rect5(110.0, 100.0, 80.0, 50.0);
//    painter.drawEllipse(rect5);

//    pen.setStyle(Qt::CustomDashLine);
//    painter.setPen(pen);
//    QRect rect6(210.0, 100.0, 80.0, 50.0);
//    painter.drawEllipse(rect6);

// ---

//    QPen pen(Qt::black);
//    pen.setStyle(Qt::SolidLine);
//    pen.setWidth(20);

//    pen.setCapStyle(Qt::FlatCap);
//    painter.setPen(pen);
//    painter.drawLine(30, 30, 200, 30);

//    pen.setCapStyle(Qt::SquareCap);
//    painter.setPen(pen);
//    painter.drawLine(30, 70, 200, 70);

//    pen.setCapStyle(Qt::RoundCap);
//    painter.setPen(pen);
//    painter.drawLine(30, 110, 200, 110);

// ---

    QPen pen(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(20);

    QPointF p1[3] = {
        QPointF(30.0, 80.0),QPointF(20.0, 40.0), QPointF(80.0, 60.0)
    };
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    painter.drawPolyline(p1, 3);

    QPointF p2[3] = {
        QPointF(130.0, 80.0), QPointF(120.0, 40.0), QPointF(180.0, 60.0)
    };
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);
    painter.drawPolyline(p2, 3);

    QPointF p3[3] = {
        QPointF(230.0, 80.0), QPointF(220.0, 40.0), QPointF(280.0, 60.0)
    };
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawPolyline(p3, 3);

    painter.end();
}

Widget::~Widget()
{

}
