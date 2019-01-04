#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QComboBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QComboBox *combo;

private slots:
    void valueChanged();

};

#endif // WIDGET_H
