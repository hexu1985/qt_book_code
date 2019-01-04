#include <QtWidgets>
#include <QDebug>
#include <QVBoxLayout>

#include "widget.h"
#include "saxParser.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createWidget();

    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Book File"),
                                         QDir::currentPath(),
                                         tr("XML Files (*.xml)"));

    createSAXParser(fileName);
}

void Widget::createWidget()
{
    QStringList labels;
    labels << tr("Title") << tr("Location");

    treeWidget = new QTreeWidget;
    treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    treeWidget->setHeaderLabels(labels);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(treeWidget);
    setLayout(vLayout);
}

void Widget::createSAXParser(QString fileName)
{
    saxParser handler(treeWidget);
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);

    QFile file(fileName);
    if(!file.open((QFile::ReadOnly | QFile::Text))){
        QMessageBox::warning(this, tr("SAX Bookmarks"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QXmlInputSource xmlInputSource(&file);
    if(reader.parse(xmlInputSource))
        qDebug("File loaded.");
}

Widget::~Widget()
{
}
