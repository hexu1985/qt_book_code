
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QDate dt1 = QDate(2013, 11, 7);
    QDate dt2 = QDate::currentDate();

    dateEdit[0] = new QDateEdit(dt1.addYears(2), this);
    dateEdit[0]->setGeometry(10, 10, 140, 40);

    dateEdit[1] = new QDateEdit(dt1.addMonths(3), this);
    dateEdit[1]->setGeometry(160, 10, 140, 40);

    dateEdit[2] = new QDateEdit(dt1.addDays(10), this);
    dateEdit[2]->setGeometry(310, 10, 140, 40);

    dateEdit[3] = new QDateEdit(dt2, this);
    dateEdit[3]->setGeometry(10, 60, 140, 40);

    // 1:mon, 2:tue, 3:wed, 4:thur, 5:fri, 6:sat, 7:sun
    qDebug("Day of year : %d", dt1.dayOfYear());
    qDebug("End Day : %d", dt1.daysInMonth());
    qDebug("End Day : %d", dt1.daysInYear());

    QDate dt3 = QDate::fromString("2002.06.26", "yyyy.MM.dd");
    QDate dt4 = QDate::fromString("06.26", "MM.dd");

    lbl[0] = new QLabel(dt3.toString(), this);
    lbl[0]->setGeometry(10,110, 150, 30);
    lbl[1] = new QLabel(dt4.toString(), this);
    lbl[1]->setGeometry(10,150, 150, 30);

    if(QDate::isValid(2011, 6, 27))
    {
        qDebug("2013.6.27 true");
    }
    else
    {
        qDebug("2013.6.27 false");
    }

    QDate dt5 = QDate(2012, 4, 26);

    QString LongWeek = dt5.longDayName(dt5.dayOfWeek());
    QString LongMonth = dt5.longMonthName(dt5.month());
    QString strDateLong = QString("%1 %2").arg(LongWeek).arg(LongMonth);

    QString ShortWeek = dt5.shortDayName(dt5.dayOfWeek());
    QString ShortMonth = dt5.shortMonthName(dt5.month());
    QString strDateShort = QString("%1 %2").arg(ShortWeek).arg(ShortMonth);


    lbl[2] = new QLabel(QString("Long: %1 , Short : %2").arg(strDateLong)
                                        .arg(strDateShort), this);
    lbl[2]->setGeometry(10, 190, 250, 30);

    QDate dt6 = QDate(2012, 7, 26);
    lbl[3] = new QLabel(dt6.toString(Qt::TextDate), this);
    lbl[3]->setGeometry(10, 240, 250, 30);

    lbl[4] = new QLabel(dt6.toString(Qt::ISODate), this);
    lbl[4]->setGeometry(10, 270, 250, 30);

    lbl[5] = new QLabel(dt6.toString(Qt::SystemLocaleDate), this);
    lbl[5]->setGeometry(10, 300, 250, 30);

}

Widget::~Widget()
{

}















