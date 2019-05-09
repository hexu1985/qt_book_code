#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QTcpSocket *tcpSocket, QObject *parent)
    : tcpSocket(tcpSocket)
{
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

QTcpSocket *TcpClientSocket::getTcpSocket()
{
    return tcpSocket;
}

TcpClientSocket::~TcpClientSocket()
{
}
                                                                             
void TcpClientSocket::dataReceived()
{
    while (tcpSocket->bytesAvailable()>0)
    {
        int length = tcpSocket->bytesAvailable();
        char buf[1024];
        tcpSocket->read(buf,length);

        QString msg=buf;
        emit updateClients(msg,length);
    }
}

void TcpClientSocket::slotDisconnected()
{
    emit disconnected(tcpSocket);
}