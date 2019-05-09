#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

class MainWidget : public QMainWindow
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent=0);
    
    void createMenu();
    
private:
    QMdiArea *mdiArea;
};

#endif 
