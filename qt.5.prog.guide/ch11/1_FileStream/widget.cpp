#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("XML Read/Write Stream"));

    edt = new QTextEdit(this);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addWidget(edt);

    setLayout(vlayout);
    resize(500, 300);

    QString inputFilePath =
        QFileDialog::getOpenFileName(this, tr("Open XML File"),
                                     QDir::currentPath(),
                                     tr("XML Files (*.xml)"));

    QFile inputFile(inputFilePath);

    if(!QFile::exists(inputFilePath))
    {
        edt->setText("File does not exist.");
    }
    else if(!inputFile.open(QIODevice::ReadOnly)) {
        edt->setText("Failed to open file.");
    }

    QFile outputFile("sampleOutput.xml");

    outputFile.open(QIODevice::WriteOnly);

    QXmlStreamReader reader(&inputFile);
    QXmlStreamWriter writer(&outputFile);

    QString inputData;
    while(!reader.atEnd())
    {
        reader.readNext();

        if(!reader.text().isEmpty())
            inputData.append(reader.text()).append("<br>");

        writer.writeCurrentToken(reader);
    }

    edt->setText(inputData);
}

Widget::~Widget()
{

}


