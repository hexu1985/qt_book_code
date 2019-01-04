#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene(0, 0, 250, 250);

    MyItem *item = new MyItem();
    item->setPos(24, 24);

    scene.addItem(item);

    QGraphicsView view(&scene);

    view.show();

    return a.exec();
}
