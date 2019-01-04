#include <QCoreApplication>

#include <QWaitCondition>
#include <QMutex>
#include <QThread>

QMutex mutex;
QWaitCondition incNumber;

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

            mutex.lock();
            ++numUsed;

            incNumber.wakeAll();
            mutex.unlock();
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
        for(int i = 0 ; i < 10 ; i++)
        {
            mutex.lock();
                incNumber.wait(&mutex);
            mutex.unlock();

            qDebug("numUsed : %d", numUsed);
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
