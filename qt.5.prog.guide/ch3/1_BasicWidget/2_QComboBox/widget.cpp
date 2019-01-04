#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("QComboBox");

    combo = new QComboBox(this);
    combo->setGeometry(50, 50, 200, 30);

    combo->addItem(QIcon(":resources/browser.png"), "Application");
    combo->addItem(QIcon(":resources/browser.png"), "Grphics");
    combo->addItem("Database");
    combo->addItem("Network");

    connect(combo, SIGNAL(currentIndexChanged(int)), this,
                    SLOT(valueChanged()));

    QString str;
    str = combo->currentText();

    qDebug("Total Items", combo->count());

    //combo->removeItem(3);
}

void Widget::valueChanged()
{
    int current_index = combo->currentIndex();
    qDebug("Current ComboBox index : %d", current_index);

}

Widget::~Widget()
{
}
