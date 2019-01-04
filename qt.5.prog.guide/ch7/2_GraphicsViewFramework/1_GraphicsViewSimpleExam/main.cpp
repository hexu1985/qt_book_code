#include "widget.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.addText("I love Qt programming", QFont("Times", 22, QFont::Bold));

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
