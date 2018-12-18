#include <QApplication>
#include "mainwidget.h"

int main(int argc, char * argv[])
{
    QApplication app(argc,argv);
    
    QTranslator translator;
    translator.load("painttrans_zh");
    app.installTranslator(&translator);
    
    MainWidget w;
    w.show();

    return app.exec();
}
