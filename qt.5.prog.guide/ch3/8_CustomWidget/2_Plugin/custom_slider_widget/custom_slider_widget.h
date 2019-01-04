#ifndef CUSTOM_SLIDER_WIDGET_H
#define CUSTOM_SLIDER_WIDGET_H

#include <QtGui/QWidget>
#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT custom_slider_widget : public QWidget
{
    Q_OBJECT

public:
    custom_slider_widget(QWidget *parent = 0);
    void slider_set_widget_resize(int width, int height);
    void slider_set_max_value(float value);
    void slider_set_min_value(float value);
    void slider_set_current_value(float value);

    int slider_get_current_value();

signals:
    void valuchanged(int value);

private:
    int w_width; // 위젯의 넓이
    int w_height; // 위젯의 높이

    float max_value; // max 값
    float min_value; // min 값
    float current_value; // 현재 값

    float slider_ypos;
    float slider_width, slider_height;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent* event);
};


#endif
