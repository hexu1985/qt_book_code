#include "widget.h"

#include <QInputDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QMessageBox msgBox(QMessageBox::Warning, tr("QMessageBox::warning()"),
                       "you save this file ?", 0, this);
    msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);


    if (msgBox.exec() == QMessageBox::AcceptRole)
        qDebug("test");

}

Widget::~Widget()
{
    
}
