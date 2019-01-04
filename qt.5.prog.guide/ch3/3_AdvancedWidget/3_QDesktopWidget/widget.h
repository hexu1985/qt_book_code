#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPixmap>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QWidget *canvas;
    QSlider *slider;
    QPixmap pixmap;

    void paintEvent(QPaintEvent *);

public slots:
    void setZoom(int);

private:
    qreal zoom;
    qreal pixels;
    qreal px_width;
    qreal px_height;
    qreal mm_width;
    qreal mm_height;
};

#endif // WIDGET_H
