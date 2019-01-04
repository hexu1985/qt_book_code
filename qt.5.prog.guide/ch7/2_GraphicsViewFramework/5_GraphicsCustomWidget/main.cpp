#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "CustomItem.h"

#define WIDTH 300
#define HEIGHT 200

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene(0, 0, 300, 200);

    CustomItem *custom_item;
    custom_item = new CustomItem(":/resources/button.png",
                                 ":/resources/button-active.png");

    custom_item->setPos(100, 100);

    scene.addItem(custom_item);

    QGraphicsView view;
    view.setScene(&scene);
    view.setFrameShape(QFrame::NoFrame);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setBackgroundBrush(Qt::black);

    view.show();

    return app.exec();
}
