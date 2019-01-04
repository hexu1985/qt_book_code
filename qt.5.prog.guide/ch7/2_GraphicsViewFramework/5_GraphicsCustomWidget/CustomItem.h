#ifndef CUSTOME_WIDGET_H
#define CUSTOME_WIDGET_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class CustomItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    CustomItem(QGraphicsItem *parent = 0);
    CustomItem(const QString normal,
                    const QString pressed = "",
                    QGraphicsItem *parent = 0);

    // paint aread
    QRectF boundingRect() const;

    // rendering function for button's image
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

    // image loading
    void setPixmap(const QString normal,
                   const QString pressed = "");

signals:
    void clicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QPixmap m_normal; // button image
    QPixmap m_pressed; // clicked image state
    bool m_isPressed;
};

#endif // WIDGET_H
