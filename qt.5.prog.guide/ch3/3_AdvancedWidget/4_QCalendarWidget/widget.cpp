#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QCalendarWidget *cal = new QCalendarWidget(this);

    cal->setMinimumDate(QDate(2014, 4, 18));
    cal->setMaximumDate(QDate(2014, 4, 22));

    //cal->setGridVisible(true);
    cal->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);

    //cal->setSelectionMode(QCalendarWidget::NoSelection);
}

Widget::~Widget()
{

}
