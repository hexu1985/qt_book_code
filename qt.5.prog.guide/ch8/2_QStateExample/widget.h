#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QState>
#include <QSignalTransition>
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QSignalTransition>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

};

#endif // WIDGET_H
