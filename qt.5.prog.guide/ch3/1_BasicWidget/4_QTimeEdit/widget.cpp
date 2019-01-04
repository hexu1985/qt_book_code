#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QTimeEdit *qte[10];

    QTime ti1 = QTime(6, 24, 55, 432); // hour, min, sec, millisecond

    qte[0] = new QTimeEdit(ti1, this);
    qte[0]->setGeometry(10, 30, 150, 30);

    qte[1] = new QTimeEdit(ti1.addMSecs(200), this);
    qte[1]->setGeometry(10, 70, 150, 30);

    qte[2] = new QTimeEdit(ti1.addSecs(2), this);
    qte[2]->setGeometry(10, 110, 150, 30);


    QTime ti2 = QTime::currentTime();

    qte[4] = new QTimeEdit(ti2.currentTime(), this);
    qte[4]->setGeometry(10, 150, 150, 30);


    QTime ti3;

    ti3.start();

    for(int i = 0 ; i < 100000 ; i++)
    {
        for(int j = 0 ; j < 10000 ; j++)
        {
        }
    }

    qDebug("Elapsed Time : %d", ti3.elapsed());

    QTime ti4 = QTime::fromString("03:32", "hh:mm");

    QLabel *lbl_fromString = new QLabel(ti4.toString(), this);
    lbl_fromString->setGeometry(10, 190, 150, 30);

    QTime ti5 = QTime(6, 25, 34, 323);
    qDebug("Hour : %d", ti5.hour());
    qDebug("min : %d", ti5.minute());
    qDebug("sec : %d", ti5.second());
    qDebug("msec : %d", ti5.msec());

    QTime ti6 = QTime(7, 10, 23, 122);
    QLabel *lbl_toString = new QLabel(ti6.toString("AP hh:mm:ss:zzz"), this);
    lbl_toString->setGeometry(10, 10, 150, 30);

}

Widget::~Widget()
{

}
