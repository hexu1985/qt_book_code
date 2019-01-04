#include "widget.h"

MyThread::MyThread(int num)
{
    number = num;
}

void MyThread::stop()
{
    threadStop = true;
    qDebug("[%d] Thread stop", number);
}

void MyThread::run()
{
    threadStop = false;
    int i = 0;

    while(!threadStop)
    {
        mutex.lock();
        qDebug("[%d] MyThread %d", number, i);
        i++;
        sleep(1);
        mutex.unlock();
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    thread1 = new MyThread(1);
    thread2 = new MyThread(2);

    QPushButton *btn_start = new QPushButton("START", this);
    btn_start->setGeometry(10, 10, 80, 40);

    QPushButton *btn_stop = new QPushButton("STOP", this);
    btn_stop->setGeometry(100, 10, 80, 40);

    QPushButton *btn_isRunning = new QPushButton("IsRunning", this);
    btn_isRunning->setGeometry(200, 10, 100, 40);

    QPushButton *btn_isFinished = new QPushButton("IsFinished", this);
    btn_isFinished->setGeometry(310, 10, 100, 40);

    connect(btn_start, SIGNAL(clicked()), this, SLOT(btn_start()));
    connect(btn_stop, SIGNAL(clicked()), this, SLOT(btn_stop()));
    connect(btn_isRunning, SIGNAL(clicked()), this, SLOT(btn_isRunning()));
    connect(btn_isFinished, SIGNAL(clicked()), this, SLOT(btn_isFinished()));

    connect(thread1, SIGNAL(stop()), this, SLOT(slot_stoped));
}

void Widget::btn_start()
{
    thread1->start();
    thread2->start();
}

void Widget::btn_stop()
{
    thread1->stop();
    thread2->stop();
}

void Widget::btn_isRunning()
{
    if(thread1->isRunning())
        qDebug("[1] Thread is running");
    else
        qDebug("[1] Thread is not running");

    if(thread2->isRunning())
        qDebug("[2] Thread is running");
    else
        qDebug("[2] Thread is not running");
}

void Widget::btn_isFinished()
{
    if(thread1->isFinished())
        qDebug("[1] Thread Finish");
    else
        qDebug("[1] Thread not Finish");

    if(thread2->isFinished())
        qDebug("[2] Thread Finish");
    else
        qDebug("[2] Thread not Finish");
}

void Widget::slot_stoped()
{
    qDebug("Thread started");
}

Widget::~Widget()
{

}
