#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class Settings : public QDialog
{
    Q_OBJECT
public:
    Settings();
    
    QLabel *label;
    QPushButton *colorBtn;
    QTextEdit *edit;
   
    void readSettings();
    void writeSettings();
    
protected:
    void closeEvent(QCloseEvent *);
    
public slots:
    void slotColor();
};

#endif // SETTINGS_H
