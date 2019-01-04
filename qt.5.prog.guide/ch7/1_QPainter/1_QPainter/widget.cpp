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

    painter.setPen(Qt::blue);
    painter.drawLine(10, 10, 100, 40); // line
    painter.drawRect(120, 10, 80, 80); // rectangle

    QRectF rect(230.0, 10.0, 80.0, 80.0);
    painter.drawRoundedRect(rect, 20, 20); // round rect

    QPointF p1[3] = {
                    QPointF(10.0, 110.0),
                    QPointF(110.0, 110.0),
                    QPointF(110.0, 190.0)
                    };

    painter.drawPolyline(p1, 3); // drawing line with points

    QPointF p2[3] = {
                    QPointF(120.0, 110.0),
                    QPointF(220.0, 110.0),
                    QPointF(220.0, 190.0)
                    };

    painter.drawPolygon(p2, 3); // drawing shape with points


    painter.setFont(QFont("Arial", 20)); // fonts
    painter.setPen(Qt::black);
    QRect font_rect(10, 150, 220, 180); // area for drawing text
    painter.drawText(font_rect, Qt::AlignCenter, "I love Qt.");

    painter.end();
}

Widget::~Widget()
{

}
