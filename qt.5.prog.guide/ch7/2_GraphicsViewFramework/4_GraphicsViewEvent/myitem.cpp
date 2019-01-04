#include "myitem.h"

MyItem::MyItem(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug("Mouse button clicked");
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug("Mouse released clicked");
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug("Mouse move");
}

void MyItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    qDebug("Mouse double clicked");
}


MyItem::~MyItem()
{

}
