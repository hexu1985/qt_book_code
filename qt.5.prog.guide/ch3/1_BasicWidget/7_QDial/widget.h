#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QDial>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QDial *dial[3];

private slots:
    void changedData();

};

#endif // WIDGET_H
