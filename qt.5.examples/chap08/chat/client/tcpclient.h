#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QHostAddress>
#include <QTcpSocket>

class TcpClient : public QDialog
{
    Q_OBJECT
public:
    TcpClient( QWidget *parent=0, Qt::WindowFlags  f=0 );
    ~TcpClient();
public:
	QListWidget *ListWidgetContent;
	QLineEdit* LineEditSend;
	QPushButton* PushButtonSend;
    QLabel* LabelUser;
    QLineEdit* LineEditUser;
    QLabel* LabelServerIP;
    QLineEdit* LineEditServerIP;    	
    QLabel* LabelPort;
    QLineEdit* LineEditPort;
    QPushButton* PushButtonEnter;
    
    QString userName;
    int port;
    QHostAddress *serverIP;
	QTcpSocket *tcpSocket;
	
	bool status;
public slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void slotSend();
    void dataReceived();
    void slotPortTextChanged(QString str);
};


#endif 
