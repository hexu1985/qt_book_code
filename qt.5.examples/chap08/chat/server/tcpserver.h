#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "server.h"
class TcpServer : public QDialog
{
    Q_OBJECT
public:
    TcpServer( QWidget *parent=0, Qt::WindowFlags  f=0 );
    ~TcpServer();
public:
	QListWidget *ListWidgetContent;
    QLabel* LabelPort;
    QLineEdit* LineEditPort;
    QPushButton* PushButtonCreate;
    
    int port;
 	Server *server;	
public slots:
    void slotCreateServer();
    void updateServer(QString,int); 
    void slotPortTextChanged(QString str);
};

#endif // TCPSERVER_H
