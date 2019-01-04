#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    resize(360, 290);

    QPushButton *button = new QPushButton("Button", this);
    button->setGeometry(10, 10, 100, 30);

    QStateMachine *machine = new QStateMachine;

    QState *state1 = new QState(machine); // state-1
    state1->assignProperty(button, "geometry", QRect(10, 10, 100, 30));
    machine->setInitialState(state1);

    QState *state2 = new QState(machine); // state-2
    state2->assignProperty(button, "geometry", QRect(250, 250, 100, 30));

    QSignalTransition *transition1 = state1->addTransition(button,
    SIGNAL(clicked()), state2); // transition-1
    transition1->addAnimation(new QPropertyAnimation(button, "geometry"));

    QSignalTransition *transition2 = state2->addTransition(button,
    SIGNAL(clicked()), state1); // transition-2
    transition2->addAnimation(new QPropertyAnimation(button, "geometry"));

    machine->start();
}

Widget::~Widget()
{

}
