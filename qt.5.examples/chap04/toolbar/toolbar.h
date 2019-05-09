#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QMainWindow>

#include <QTextEdit>
#include <QSpinBox>
#include <QComboBox>

class ToolBar : public QMainWindow
{
    Q_OBJECT
public:
    ToolBar();
    
public slots:
    void slotComboBox(QString);
    void slotSpinBox(QString);
    
private:
    QTextEdit *text;
    QSpinBox *spin;
    QComboBox *box;
};

#endif  // TOOLBAR_H
