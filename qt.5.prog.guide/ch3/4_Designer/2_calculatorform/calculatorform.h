
#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

//! [0]
#include "ui_calculatorform.h"
//! [0]

//! [1]
class CalculatorForm : public QWidget
{
    Q_OBJECT

public:
    CalculatorForm(QWidget *parent = 0);

private slots:
    void on_inputSpinBox1_valueChanged(int value);
    void on_inputSpinBox2_valueChanged(int value);

private:
    Ui::CalculatorForm ui;
};
//! [1]

#endif
