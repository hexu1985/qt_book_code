#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("QGraphicsEffect");
    w.setFixedSize(700, 360);

    w.show();

    return a.exec();
}
