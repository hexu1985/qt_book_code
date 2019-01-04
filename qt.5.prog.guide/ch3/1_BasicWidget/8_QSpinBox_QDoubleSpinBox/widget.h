#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QDoubleSpinBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QSpinBox *spin[3];
    QDoubleSpinBox *doublespin[3];

private slots:
    void valueChange();
    void double_valueChange();

};

#endif // WIDGET_H
