#include "CustomItem.h"

CustomItem::CustomItem(QGraphicsItem *parent)
                : QGraphicsItem(parent), m_isPressed(false)
{
}

CustomItem::CustomItem(const QString normal,
                       const QString pressed,
                       QGraphicsItem *parent)
                : QGraphicsItem(parent), m_isPressed(false)
{
    setPixmap(normal, pressed);
}

QRectF CustomItem::boundingRect() const
{
    return m_normal.rect();
}

void CustomItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (m_isPressed)
        painter->drawPixmap(0, 0, m_pressed);
    else
        painter->drawPixmap(0, 0, m_normal);
}

void CustomItem::setPixmap(QString normal, QString pressed)
{
    if (! m_normal.isNull())
    {
        m_normal.detach();
        m_pressed.detach();
    }

    m_normal.load(normal);
    m_pressed.load(pressed);
}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (contains(event->pos()))
            m_isPressed = true;

        update();
    }
}

void CustomItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        if (contains(event->pos()))
        {
            m_isPressed = true;
        }
        else
        {
            m_isPressed = false;
        }

        update();
    }
}

void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isPressed = false;

        update();

        if (contains(event->pos()))
        {
            emit clicked();
        }
    }
}

