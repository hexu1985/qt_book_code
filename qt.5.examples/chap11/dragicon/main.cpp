#include "dragwidget.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char * argv[])
{
    QFont font("ZYSong18030",12);
    QApplication::setFont(font);	
    
    QApplication app(argc,argv);
    QTranslator translator(0);
    translator.load("dragwidget_zh",".");
    app.installTranslator(&translator);    
    
    DragWidget *mainWidget = new DragWidget;
    mainWidget->show();
    
    return app.exec();
}
