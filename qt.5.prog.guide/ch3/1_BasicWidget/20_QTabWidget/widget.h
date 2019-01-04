#ifndef WIDGET_H
#define WIDGET_H

#include <QTabWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void currentTab(int index);

};

#endif // WIDGET_H
