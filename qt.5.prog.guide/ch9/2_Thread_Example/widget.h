#ifndef WIDGET_H
#define WIDGET_H

#include <QThread>
#include <QTextEdit>
#include <QPushButton>
#include <QMutex>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(int num);

private:
    bool threadStop;
    int number;
    QMutex mutex;

public:
    void stop();

protected:
    void run();
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    MyThread *thread1;
    MyThread *thread2;

private slots:
    void btn_start();
    void btn_stop();
    void btn_isRunning();
    void btn_isFinished();

    void slot_stoped();
};

#endif // WIDGET_H
