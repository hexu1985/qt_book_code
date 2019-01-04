#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 300);
    QSplitter *splitter = new QSplitter(this);

    // Model class
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    // View widget - QTreeView
    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    // View widget - QListView
    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(splitter);
    setLayout(layout);

}

Widget::~Widget()
{

}
