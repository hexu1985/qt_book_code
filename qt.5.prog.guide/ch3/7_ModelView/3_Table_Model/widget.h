#ifndef WIDGET_H
#define WIDGET_H

#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QtWidgets/QVBoxLayout>
#include <QDateTime>
#include <QtWidgets/QTableView>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    void addModel(QAbstractItemModel *model, const QString &subject,
                  const QString &desc, const QDateTime &date);

};

#endif // WIDGET_H
