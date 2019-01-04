#include "saxParser.h"

saxParser::saxParser(QTreeWidget *treeWidget)
    :treeWidget(treeWidget)
{
}

bool saxParser::startElement(const QString &/* namespaceURI */,
                             const QString &/* localName */,
                             const QString &qName,
                             const QXmlAttributes &atts)
{
    if(qName == "books"){
        if(atts.value("version") != "1.0"){
            return false;
        }
    }else if(qName == "bookmark"){
        item = createChildItem(qName);
        item->setText(1, atts.value("url"));
    }
    return true;
}

bool saxParser::endElement(const QString &/* namespaceURI */,
                           const QString &/* localName */,
                           const QString &qName)
{
    if(qName == "title"){
        item = createChildItem(qName);
        item->setText(0, currentText);
    }

    return true;
}

bool saxParser::characters(const QString &str)
{
    if(!str.isEmpty())
        currentText = str;
    return true;
}

QTreeWidgetItem *saxParser::createChildItem(const QString &tagName)
{
    QTreeWidgetItem *childItem;

    if(tagName == "title")
        childItem = new QTreeWidgetItem(treeWidget);
    else
        childItem = new QTreeWidgetItem(item);

    childItem->setData(0, Qt::UserRole, tagName);
    return childItem;
}


