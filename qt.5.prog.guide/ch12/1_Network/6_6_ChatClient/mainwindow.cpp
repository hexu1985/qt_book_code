#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this,
                    SLOT(readyRead()));

    connect(socket, SIGNAL(connected()), this,
                    SLOT(connected()));
}

void MainWindow::on_loginButton_clicked()
{
    socket->connectToHost(ui->serverLineEdit->text(), 9999);
}

void MainWindow::on_sayButton_clicked()
{
    QString message = ui->sayLineEdit->text().trimmed();

    if(!message.isEmpty())
    {
        socket->write(QString(message + "\n").toUtf8());
    }

    ui->sayLineEdit->clear();
    ui->sayLineEdit->setFocus();
}

void MainWindow::readyRead()
{
    while(socket->canReadLine())
    {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        QRegExp messageRegex("^([^:]+):(.*)$");

        if(messageRegex.indexIn(line) != -1)
        {
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

            ui->roomTextEdit->append("<b>"+user+"</b>: "+message);
        }
    }
}

void MainWindow::connected()
{
    ui->stackedWidget->setCurrentWidget(ui->chatPage);
    socket->write(QString("/me:"+ui->userLineEdit->text()
                                +"\n").toUtf8());
}

MainWindow::~MainWindow()
{
    delete ui;
}
