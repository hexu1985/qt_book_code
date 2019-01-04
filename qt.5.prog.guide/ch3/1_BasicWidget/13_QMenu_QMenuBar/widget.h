#ifndef WIDGET_H
#define WIDGET_H

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QMenu       *menu[3];
    QMenuBar    *menuBar;
    QLabel      *lbl;
    QAction     *act[2];

private slots:
    void trigerMenu(QAction *act);

};

#endif // WIDGET_H
