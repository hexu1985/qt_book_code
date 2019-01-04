#include "widget.h"

Widget::Widget(QWidget *parent) : QGraphicsView(parent)
{
    setScene(&m_scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setupScene();

    setRenderHint(QPainter::Antialiasing, true);
    setFrameStyle(QFrame::NoFrame);
}

void Widget::setupScene()
{
    QGraphicsRectItem *parent = m_scene.addRect(0, 0, 500, 500);
    parent->setPen(Qt::NoPen);
    parent->setZValue(0);

    QPixmap pixmap(":/resources/lena.png");
    QGraphicsPixmapItem *bg = m_scene.addPixmap(pixmap);
    bg->setParentItem(parent);
    bg->setZValue(1);

    m_effect = new QGraphicsBlurEffect;
    m_effect->setBlurRadius(10);
    m_effect->setEnabled(true);
    parent->setGraphicsEffect(m_effect);
}

Widget::~Widget()
{

}
