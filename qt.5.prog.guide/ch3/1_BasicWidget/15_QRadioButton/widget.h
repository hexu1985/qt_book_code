#ifndef WIDGET_H
#define WIDGET_H

#include <QRadioButton>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QRadioButton *radio1[3];
    QRadioButton *radio2[3];

};

#endif // WIDGET_H
