#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

class MyItem : public QGraphicsItem
{

public:
    MyItem(QGraphicsItem *parent = 0);
    ~MyItem();

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 200, 200);
    }

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *)
    {
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(Qt::blue);

        painter->drawRoundedRect(0, 0, 200, 200, 5, 5);
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYITEM_H
