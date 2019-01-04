#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
Widget w;
w.resize(400, 300);

SubWindow subWindow(&w);
subWindow.move(200, 180);

w.show();

return a.exec();
}
