#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("MeeGo exmaple for Plugin Export");
    ui->slider_widget->slider_set_widget_resize(24, 100);
    ui->slider_widget->slider_set_max_value(22);
    ui->slider_widget->slider_set_min_value(0);
    ui->slider_widget->slider_set_current_value(12);

    connect(ui->slider_widget, SIGNAL(valuchanged(int)), this,
                                SLOT(mvaluechanged(int)));
}

void Widget::mvaluechanged(int value)
{
    ui->cpu_widget->cpu_set_widget_level(value);
}

Widget::~Widget()
{
    delete ui;
}
