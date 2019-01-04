#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTreeWidget;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    void createWidget();
    void createSAXParser(QString fileName);
    QTreeWidget *treeWidget;

};

#endif // WIDGET_H
