#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 300);
    QStringList strList;
    strList << "Monday" << "Tuesday" << "Wedneday"
            << "Thurday" << "Friday";

    QAbstractItemModel *model = new QStringListModel(strList);

    QListView *view = new QListView();
    view->setModel(model);

    QModelIndex index = model->index(3, 0);
    QString text = model->data(index, Qt::DisplayRole).toString();

    QLabel *lbl = new QLabel("");
    lbl->setText(text);

    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(view);
    lay->addWidget(lbl);

    setLayout(lay);

}

Widget::~Widget()
{

}
