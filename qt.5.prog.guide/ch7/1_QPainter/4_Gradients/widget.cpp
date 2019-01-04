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

    /*
    QLinearGradient ling(QPointF(70, 70), QPoint( 140, 140 ) );
    ling.setColorAt(0, Qt::blue);
    ling.setColorAt(1, Qt::green);

    //ling.setSpread( QGradient::PadSpread );
    //ling.setSpread( QGradient::RepeatSpread );
    ling.setSpread( QGradient::ReflectSpread );

    QBrush brush(ling);
    painter.setBrush(brush);
    painter.drawRect(0, 0, 200, 200);
    */

    // --
    /*
    QRadialGradient radg(100, 100, 50, 120, 120);
    //radg.setSpread(QGradient::PadSpread);
    //radg.setSpread(QGradient::RepeatSpread);
    radg.setSpread(QGradient::ReflectSpread);
    radg.setColorAt( 0, Qt::black );
    radg.setColorAt( 1, Qt::white );

    QBrush brush(radg);
    painter.setBrush(brush);
    painter.drawRect(0, 0, 200, 200);
    */
    // ---

    QConicalGradient cong( 100, 100, 45.0 );
    cong.setColorAt( 0, Qt::black );
    cong.setColorAt( 1, Qt::white );

    QBrush brush(cong);
    painter.setBrush(brush);
    painter.drawRect(0, 0, 200, 200);


    painter.end();
}

Widget::~Widget()
{

}
