#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    cmmBtn = new QCommandLinkButton("Vision",
                                    "Vision Project",
                                    this);

    cmmBtn->setFlat(true);

    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(clickFunc()));
}

void Widget::clickFunc()
{
    qDebug("QCommandLinkButton Click.");
}

Widget::~Widget()
{
}
