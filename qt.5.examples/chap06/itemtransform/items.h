#ifndef ITEMS_H
#define ITEMS_H

#include <QGraphicsItem>

class QGraphicsSceneMouseEvent;

class PixItem : public QGraphicsItem , public QObject
{
public:
    PixItem(QPixmap *pixmap);
    
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    
    void scale(qreal sx, qreal sy) 
    {
        setTransform(QTransform::fromScale(sx, sy), true);
    }

    void rotate(qreal angle)
    {
        setTransform(QTransform().rotate(angle), true);
    }

    void shear(qreal sh, qreal sv)
    {
        setTransform(QTransform().shear(sh, sv), true);
    }

    void translate(qreal dx, qreal dy)
    {
        setTransform(QTransform::fromTranslate(dx, dy), true);
    }

private:
    QPixmap pix;

    QTimer *timer;
};


#endif 	// ITEMS_H
