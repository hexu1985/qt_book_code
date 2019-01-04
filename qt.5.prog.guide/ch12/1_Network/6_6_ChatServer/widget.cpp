#include "widget.h"
#include "chatServer.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnStart, SIGNAL(clicked()), this,
                          SLOT(slots_btnStart()));

    server = new chatServer();
    connect(server, SIGNAL(clients_signal(int)), this,
                    SLOT(slot_clients(int)));
    connect(server, SIGNAL(message_signal(QString)), this,
                    SLOT(slot_message(QString)));
}

void Widget::slots_btnStart()
{
    bool success = server->listen(QHostAddress::Any, 9999);

    if(success){
        ui->textEdit->append("Chat Server start");

    }else{
        ui->textEdit->append("Chat Server error");
    }
}

void Widget::slot_clients(int users)
{
    QString str = QString("Clients : %1").arg(users);
    ui->label->setText(str);
}

void Widget::slot_message(QString msg)
{
    ui->textEdit->append(msg);
}

Widget::~Widget()
{
    delete ui;
}
