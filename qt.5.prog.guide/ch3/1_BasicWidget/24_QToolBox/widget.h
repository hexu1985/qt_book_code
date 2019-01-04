#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolBox>
#include<QHBoxLayout>
#include<QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QToolBox *box;
    QHBoxLayout *lay;
    QPushButton *but1;
    QPushButton *but2;
    QPushButton *but3;

private slots:
    void changedTab(int index);
};

#endif // WIDGET_H
