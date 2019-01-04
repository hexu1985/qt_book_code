#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QLCDNumber>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:

};

#endif // WIDGET_H
