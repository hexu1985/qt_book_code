#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QLabel and QLCDNumber Widget");

    QLabel  *lbl[3];

    lbl[0] = new QLabel("I love Qt programming", this);
    lbl[0]->setGeometry(10, 30, 130, 40);

    QPixmap pix = QPixmap(":resources/browser.png");
    lbl[1] = new QLabel(this);
    lbl[1]->setPixmap(pix);
    lbl[1]->setGeometry(10, 70, 100, 100);

    QLCDNumber *lcd[3];
    lcd[0] = new QLCDNumber(2, this);
    lcd[0]->display(24);
    lcd[0]->setGeometry(150, 30, 200, 100);
    lcd[0]->setSegmentStyle(QLCDNumber::Outline);

    lcd[1] = new QLCDNumber(5, this);
    lcd[1]->display("10:34");
    lcd[1]->setGeometry(150, 140, 200, 100);
    lcd[1]->setSegmentStyle(QLCDNumber::Filled);

    lcd[2] = new QLCDNumber(5, this);
    lcd[2]->display("10:34");
    lcd[2]->setGeometry(150, 250, 200, 100);
    lcd[2]->setSegmentStyle(QLCDNumber::Flat);

}

Widget::~Widget()
{

}
