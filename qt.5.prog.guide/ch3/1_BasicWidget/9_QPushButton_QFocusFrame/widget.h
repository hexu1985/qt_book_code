#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QFocusFrame>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void btn_click();
    void btn_pressed();
    void btn_released();

};

#endif // WIDGET_H
