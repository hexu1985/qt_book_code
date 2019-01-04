#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QCommandLinkButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QCommandLinkButton *cmmBtn;

private slots:
    void clickFunc();

};

#endif // WIDGET_H
