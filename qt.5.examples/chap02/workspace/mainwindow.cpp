#include "mainwindow.h"
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

MainWidget::MainWidget(QWidget *parent)
	: QMainWindow(parent)
{   
    setWindowTitle(tr("Workspace"));
    
    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);  
    
    createMenu(); 
    
    QMainWindow *window1 = new QMainWindow;
    window1->setWindowTitle(tr("window 1"));
    QTextEdit *edit1 = new QTextEdit;
    edit1->setText(tr("Window 1"));
    window1->setCentralWidget(edit1);
    
    QMainWindow *window2 = new QMainWindow;
    window2->setWindowTitle(tr("window 2"));
    QTextEdit *edit2 = new QTextEdit;
    edit2->setText(tr("Window 2"));
    window2->setCentralWidget(edit2);
    
    QMainWindow *window3 = new QMainWindow;
    window3->setWindowTitle(tr("window 3"));
    QTextEdit *edit3 = new QTextEdit;
    edit3->setText(tr("Window 3"));
    window3->setCentralWidget(edit3);
    
    mdiArea->addSubWindow(window1);
    mdiArea->addSubWindow(window2);
    mdiArea->addSubWindow(window3);

}

void MainWidget::createMenu()
{
    QMenu *layoutMenu = menuBar()->addMenu(tr("Layout"));
    
    QAction *tile = new QAction(tr("tile"),this);
    connect(tile,SIGNAL(triggered()),mdiArea,SLOT(tileSubWindows()));
    layoutMenu->addAction(tile);
    
    QAction *cascade = new QAction(tr("cascade"),this);
    connect(cascade,SIGNAL(triggered()),mdiArea,SLOT(cascadeSubWindows()));
    layoutMenu->addAction(cascade);
    
    
    QMenu *otherMenu = menuBar()->addMenu(tr("Other"));
    
    QAction *nextAct = new QAction(tr("Next"),this);
    connect(nextAct,SIGNAL(triggered()),mdiArea,SLOT(activateNextSubWindow()));
    otherMenu->addAction(nextAct);
    
    QAction *previousAct = new QAction(tr("Previous"),this);
    connect(previousAct,SIGNAL(triggered()),mdiArea,SLOT(activatePreviousSubWindow()));
    otherMenu->addAction(previousAct);
}



