#ifndef SAXPARSER_H
#define SAXPARSER_H

#include <QXmlDefaultHandler>
#include <QTreeWidget>

class saxParser : public QXmlDefaultHandler
{
public:
    saxParser(QTreeWidget *treeWidget);
    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI,
                    const QString &localName, const QString &qName);
    bool characters(const QString &str);

private:
    QTreeWidgetItem *createChildItem(const QString &tagName);
    QTreeWidget *treeWidget;
    QTreeWidgetItem *item;
    QString currentText;
};

#endif // SAXPARSER_H
