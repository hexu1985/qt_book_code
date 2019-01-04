#ifndef WIDGET_H
#define WIDGET_H

#include <QFontComboBox>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel *lbl;

private slots:
    void changedIndex(int idx);
    void changedFont(const QFont &f);


};

#endif // WIDGET_H
