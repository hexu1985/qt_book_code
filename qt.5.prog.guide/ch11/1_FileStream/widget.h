#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFileDialog>

enum ExitCode
{
    Success,
    ParseFailure,
    ArgumentError,
    WriteError,
    FileFailure
};


class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QTextEdit *edt;
};

#endif // WIDGET_H
