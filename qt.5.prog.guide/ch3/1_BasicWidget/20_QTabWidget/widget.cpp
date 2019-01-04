#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QTabWidget *tab = new QTabWidget(this);

    QWidget *browser_tab = new QWidget;
    QWidget *users_tab = new QWidget;

    tab->addTab(browser_tab, QIcon(":resources/browser.png"), "Browser");
    tab->addTab(users_tab, QIcon(":resources/users.png"), "Users");

    tab->setGeometry(20, 20, 300, 250);

    QString btn_str[3] = {"Button 1", "Button 2", "Button 3"};
    QPushButton *btn[3];

    int ypos = 30;
    for(int i = 0 ; i < 3 ; i++)
    {
        btn[i] = new QPushButton(btn_str[i], browser_tab);
        btn[i]->setGeometry(10, ypos, 100, 40);
        ypos += 50;
    }

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
