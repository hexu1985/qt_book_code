#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QAction>

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void createMenus();
    void loadFile(const QString &fileName);

    QMenu *fileMenu;
    QAction *openAct;
    QHBoxLayout *layout;
    QPlainTextEdit *textEdit;
    QString fileName;

private slots:
    void open();

};

#endif // MAINWINDOW_H
