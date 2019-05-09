#include "httpclient.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

HttpClient::HttpClient( QWidget *parent, Qt::WindowFlags  f )
    : QDialog( parent, f )
{  
    QFont font("ZYSong18030",12);
    setFont(font);	
    
    setWindowTitle(tr("Http Client"));
    
    urlLabel = new QLabel( this );
    urlLabel->setText(tr("Url:"));
    
    urlLineEdit = new QLineEdit( this );
    
    progressBar = new QProgressBar( this );
    
    downloadPushButton = new QPushButton( this);
    downloadPushButton->setText( tr( "Download" ) );  
    
    cancelPushButton = new QPushButton( this);
    cancelPushButton->setText( tr( "Cancel" ) );      
    
    exitPushButton = new QPushButton( this);
    exitPushButton->setText( tr( "Exit" ) );      
    
    QHBoxLayout *hbLayout1 = new QHBoxLayout();
    hbLayout1->addWidget( urlLabel );
    hbLayout1->addWidget( urlLineEdit );

    QHBoxLayout *hbLayout2 = new QHBoxLayout();
    hbLayout2->addWidget( progressBar );
    
    QHBoxLayout *hbLayout3 = new QHBoxLayout();
    hbLayout3->addWidget( downloadPushButton );
    hbLayout3->addWidget( cancelPushButton ); 
    hbLayout3->addWidget( exitPushButton );    
    
    QVBoxLayout *vbLayout = new QVBoxLayout( this );
    vbLayout->addLayout( hbLayout1 );
    vbLayout->addLayout( hbLayout2 );
    vbLayout->addLayout( hbLayout3 );

    manager = new QNetworkAccessManager(this);

	connect(downloadPushButton,SIGNAL(clicked()),this,SLOT(slotDownload()));
    connect(cancelPushButton,SIGNAL(clicked()),this,SLOT(slotCancel()));
    connect(exitPushButton,SIGNAL(clicked()),this,SLOT(slotExit()));
    
	cancelPushButton->setEnabled(false);

}

HttpClient::~HttpClient()
{
}
                                                                             
void HttpClient::slotDownload()
{
	QUrl url(urlLineEdit->text());
    QFileInfo fileInfo(url.path());
    QString fileName = fileInfo.fileName();

    if (QFile::exists(fileName)) 
    {
        QMessageBox::information(this, tr("Error"),tr("File already exists!"));
        return;
    }

    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) 
    {
        QMessageBox::information(this, tr("Error"),tr("Save file error!"));
        delete file;
        file = 0;
        return;
    }
    
    httpRequestAborted = false;
    reply = manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(httpDataReadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));

    progressBar->reset();

    downloadPushButton->setEnabled(false);
    cancelPushButton->setEnabled(true);
}

void HttpClient::slotCancel()
{
    httpRequestAborted = true;
    reply->abort();
    downloadPushButton->setEnabled(true);
    cancelPushButton->setEnabled(false);	
}
	
void HttpClient::slotExit()
{
	accept();
}

void HttpClient::httpFinished()
{
    if (httpRequestAborted) 
    {
        if (file) 
        {
            file->close();
            file->remove();
            delete file;
            file = 0;
        }

        progressBar->reset();
        return;
    }

    progressBar->reset();
    file->close();

    if (reply->error()) 
    {
        file->remove();
        QMessageBox::information(this, tr("Error"),tr("Download failed!"));
    } 

    downloadPushButton->setEnabled(true);
    cancelPushButton->setEnabled(false);
    delete file;
    file = 0;

    reply->deleteLater();
    reply = 0;

    QMessageBox::information(this, tr("Success"),tr("Download success!"));
}

void HttpClient::httpDataReadProgress(qint64 done, qint64 total)
{
	progressBar->setMaximum(total);
    progressBar->setValue(done);
}

void HttpClient::httpReadyRead()
{
    if (file) file->write(reply->readAll());
}
