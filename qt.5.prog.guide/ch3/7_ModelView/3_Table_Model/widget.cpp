#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStandardItemModel *model = new QStandardItemModel(0, 3);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Subject"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));



    model->setVerticalHeaderItem(0, new QStandardItem("Col 1"));
    model->setVerticalHeaderItem(1, new QStandardItem("Col 2"));
    model->setVerticalHeaderItem(2, new QStandardItem("Col 3"));



model->setData(model->index(0, 0), "Monitor");
model->setData(model->index(0, 1), "LCD 24 inch");
model->setData(model->index(0, 2), QDateTime(QDate(2013, 10, 4)));

model->setData(model->index(1, 0), "CPU");
model->setData(model->index(1, 1), "Intel core 2 duo");
model->setData(model->index(1, 2), QDateTime(QDate(2013, 12, 5)));

model->setData(model->index(2, 0), "Keyboard");
model->setData(model->index(2, 1), "104 key USB Keyboard");
model->setData(model->index(2, 2), QDateTime(QDate(2013, 12, 6)));


/*
    addModel(model, "Monitor", "LCD 24 inch",
                                QDateTime(QDate(2011, 10, 4)));
    addModel(model, "CPU", "Intel core 2 duo",
                                QDateTime(QDate(2011, 12, 5)));
    addModel(model, "Keyboard", "104 key USB Keyboard",
                                QDateTime(QDate(2011, 12, 6)));
*/
    QTableView *table = new QTableView();
    table->setModel(model);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(table);

    setLayout(lay);
}

void Widget::addModel(QAbstractItemModel *model, const QString &subject,
             const QString &desc, const QDateTime &date)
{
    model->insertRow(0);
    model->setData(model->index(0, 1), subject);
    model->setData(model->index(0, 2), desc);
    model->setData(model->index(0, 3), date);
}

Widget::~Widget()
{

}

