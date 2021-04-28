//
// Created by pikachu on 2021/4/13.
//

#include "WordReader.h"
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QXmlStreamReader>
#include <private/qzipwriter_p.h>
#include <private/qzipreader_p.h>


WordReader::WordReader(const QString &path): m_path(path) {

}


QString WordReader::readAll() {

    QZipReader zipReader(m_path);
    QXmlStreamReader reader;
    QString ret;
    int count = 0;
    reader.addData(zipReader.fileData("word/document.xml"));
    while (!reader.atEnd()) {
        if (reader.isStartElement()) {
            if (reader.name() == QString("p")) {
                // count++;
                // ret += QString::number(count);
                // ret += ". ";
            }
            if (reader.name() == QString("t")) {
                ret += reader.readElementText();
                // ret += '\n';
            }
        }
        if (reader.isEndElement()) {
            if (reader.name() == QString("p")) {
                ret += '\n';
            }
        }
        reader.readNext();
    }
    return ret;
}
