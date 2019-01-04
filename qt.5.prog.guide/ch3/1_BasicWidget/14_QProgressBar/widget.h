#ifndef WIDGET_H
#define WIDGET_H

#include <QProgressBar>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QProgressBar *progress[4];

};

#endif // WIDGET_H
