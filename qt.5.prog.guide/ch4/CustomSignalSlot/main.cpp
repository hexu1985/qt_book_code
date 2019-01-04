#include <QtWidgets/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.resize(400, 300);
    w.setWindowTitle("Custom Signal Slot");

    w.show();

    return a.exec();
}
