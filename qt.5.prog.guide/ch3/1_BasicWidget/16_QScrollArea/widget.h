#ifndef WIDGET_H
#define WIDGET_H

#include <QScrollArea>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QImage image;
    QScrollArea *area;

};

#endif // WIDGET_H
