#include "widget.h"

#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(621, 375);

    QHBoxLayout *layout = new QHBoxLayout;

    canvas = new QWidget;
    slider = new QSlider;
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(50);

    layout->addWidget(canvas);
    layout->addWidget(slider);

    setLayout(layout);

    if(!pixmap.load(":/resources/fish.png"))
    {
        qDebug() << "Fatal error: Unable to load image";
        exit(-1);
    }

    connect(slider, SIGNAL(valueChanged(int)),
            SLOT(setZoom(int)));

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter paint;
    paint.begin(this);
    paint.scale(zoom, zoom);
    paint.drawPixmap(0,0, pixmap);
    paint.end();
}

void Widget::setZoom(int new_zoom)
{

    zoom = (qreal)(50+new_zoom) / 50;
    pixels = pixmap.width() * zoom;

    QDesktopWidget desk;
    px_width = desk.width() / pixels;
    px_height = desk.height() / pixels;
    mm_width = px_width * 17.9;
    mm_height = px_height * 17.9;

    qDebug() << "Zoom: " << zoom;
    qDebug() << "desk.widthMM:" << desk.widthMM();
    qDebug() << "px_width: " << px_width;
    qDebug() << "px_height: " << px_height;
    qDebug() << "mm_width: " << mm_width;
    qDebug() << "mm_height: " << mm_height;

    repaint();
}

Widget::~Widget()
{
    
}
















