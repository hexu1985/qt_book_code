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

//    painter.setBrush(QBrush(Qt::green, Qt::Dense3Pattern));
//    painter.setPen(Qt::blue);
//    painter.drawEllipse(10, 10, 100,100);

//    painter.setBrush(Qt::NoBrush);
//    painter.setPen(Qt::blue);
//    painter.drawEllipse(80, 10, 100, 100);

    //-----------

//    QPixmap pixmap(":resources/qtblog.png");
//    int w = pixmap.width();
//    int h = pixmap.height();
//    pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

//    QBrush brush(pixmap);
//    painter.setBrush(brush);
//    painter.setPen(Qt::blue);
//    painter.drawRect(0, 0, w, h);

    //-----------

    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));
    QBrush brush(gradient);

    painter.setBrush(brush);
    painter.drawRect(0, 0, 100, 100);

    painter.end();
}

Widget::~Widget()
{
}
