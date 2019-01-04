#ifndef WIDGET_H
#define WIDGET_H

#include <QDate>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QDateEdit *dateEdit[4];
    QLabel *lbl[6];
};

#endif // WIDGET_H
