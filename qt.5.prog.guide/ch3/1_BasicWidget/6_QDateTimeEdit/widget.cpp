#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QDateTimeEdit *qde1;
    qde1 = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    qde1->setDisplayFormat("yyyy-MM-dd hh:mm:ss:zzz");
    qde1->setGeometry(10, 30, 250, 50);

    QDateTimeEdit *qde[3];

    qde[0] = new QDateTimeEdit(QDate::currentDate(), this);
    qde[0]->setMinimumDate(QDate::currentDate().addYears(-3));
    qde[0]->setMaximumDate(QDate::currentDate().addYears(3));
    qde[0]->setDisplayFormat("yyyy");
    qde[0]->setGeometry(10, 90, 100, 50);

    qde[1] = new QDateTimeEdit(QDate::currentDate(), this);
    qde[1]->setMinimumDate(QDate::currentDate().addMonths(-2));
    qde[1]->setMaximumDate(QDate::currentDate().addMonths(2));
    qde[1]->setDisplayFormat("MM");
    qde[1]->setGeometry(110, 90, 100, 50);

    qde[2] = new QDateTimeEdit(QDate::currentDate(), this);
    qde[2]->setMinimumDate(QDate::currentDate().addDays(-20));
    qde[2]->setMaximumDate(QDate::currentDate().addDays(20));
    qde[2]->setDisplayFormat("dd");
    qde[2]->setGeometry(210, 90, 100, 50);

}

Widget::~Widget()
{
}
