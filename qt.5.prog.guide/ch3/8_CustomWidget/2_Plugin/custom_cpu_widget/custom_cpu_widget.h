#ifndef CUSTOM_CPU_WIDGET_H
#define CUSTOM_CPU_WIDGET_H

#include <QtWidgets>
#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT custom_cpu_widget : public QWidget
{
    Q_OBJECT

public:
    custom_cpu_widget(QWidget *parent = 0);
    void cpu_set_widget_level(int level);

private:
    int w_width;
    int w_height;
    int cpu_used_level;

protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif
