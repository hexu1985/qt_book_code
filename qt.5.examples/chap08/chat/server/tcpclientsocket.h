#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>

class TcpClientSocket: public QObject
{
    Q_OBJECT

private:
    QTcpSocket *tcpSocket;

public:
    TcpClientSocket(QTcpSocket *tcpSocket, QObject *parent=0);
    ~TcpClientSocket();
    QTcpSocket *getTcpSocket();

signals:
    void updateClients(QString,int);
    void disconnected(QTcpSocket *);

protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // TCPCLIENTSOCKET_H
