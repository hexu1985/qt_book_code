#ifndef PARARW_H
#define PARARW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>

class ParaRW : public QDialog
{
    Q_OBJECT
public:
    ParaRW();
    
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *timeLabel;
    QPushButton *saveButton;
    QPushButton *getButton;
    QComboBox *powerComboBox;
    QSpinBox *channelSpinBox;
    QLineEdit *frequencyEdit;
    
public slots:
    void slotSave();
    void slotGet();  
   
};

#endif  // PARARW_H
