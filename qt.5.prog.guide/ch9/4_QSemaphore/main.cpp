#include <QCoreApplication>

#include <QSemaphore>
#include <QThread>

QSemaphore incNumber;
int numUsed;

class Producer : public QThread
{
public:
    Producer()
    {
    }

protected:
    void run()
    {
        for(int i = 0 ; i < 10 ; i++){
            sleep(1);
            ++numUsed;
            qDebug("[Producer] numUsed : %d", numUsed);
            incNumber.release();
        }

    }
};

class Consumer : public QThread
{
public:
    Consumer()
    {
    }

protected:
    void run()
    {

        for(int i = 0 ; i < 10 ; i++){
            incNumber.acquire();
            qDebug("[Consumer] numUsed : %d", numUsed);
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();

    return a.exec();
}
