#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTabBar *tab = new QTabBar(this);

    tab->addTab("Browser");
    tab->addTab("User");
    tab->addTab("Application");

    tab->setGeometry(20, 20, 300, 250);

    connect(tab, SIGNAL(currentChanged(int)), this,
            SLOT(currentTab(int)));

}

void Widget::currentTab(int index)
{
    qDebug("Current Tab : %d", index);
}

Widget::~Widget()
{
    
}
