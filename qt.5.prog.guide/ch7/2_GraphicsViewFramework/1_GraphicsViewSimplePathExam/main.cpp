#include "widget.h"
#include <QApplication>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainterPath>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;

    QPainterPath path;
    path.moveTo(30,120);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    scene.addPath(path, QPen(Qt::black), QBrush(Qt::green));
    scene.addText("I love Qt programming.", QFont("Times", 15, QFont::Bold));

    QGraphicsView view(&scene);
    view.show();

    
    return a.exec();
}
