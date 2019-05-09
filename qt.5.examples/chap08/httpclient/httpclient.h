#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QtNetwork>
#include <QProgressBar>

class HttpClient : public QDialog
{
    Q_OBJECT
public:
    HttpClient( QWidget *parent=0, Qt::WindowFlags  f=0 );
    ~HttpClient();
public:
	QLabel* urlLabel;
	QLineEdit* urlLineEdit;
	QLabel* LabelUser;
	QProgressBar* progressBar;
    QPushButton* downloadPushButton;
    QPushButton* cancelPushButton;
    QPushButton* exitPushButton;

    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile* file;
    
	bool httpRequestAborted;
public slots:
    void slotDownload();
    void slotCancel();
    void slotExit();
    void httpFinished();
    void httpDataReadProgress(qint64, qint64);
    void httpReadyRead();
};


#endif
