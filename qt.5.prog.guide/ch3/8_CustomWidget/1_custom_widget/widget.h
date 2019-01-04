#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

#include "custom_cpu_widget.h"
#include "custom_slider_widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void mvaluechanged(int value);

private:
    custom_cpu_widget *cpu_widget;
    custom_slider_widget *slider_widget;

private:
    bool m_embedded;
    QPixmap m_device;

protected:
    void update_background();

protected:
    virtual void paintEvent(QPaintEvent* event);

};

#endif // WIDGET_H
