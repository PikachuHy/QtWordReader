//
// Created by pikachu on 2021/4/13.
//

#ifndef MYNOTES_WORDREADER_H
#define MYNOTES_WORDREADER_H
#include "QtWordReader_global.h"
#include <QString>
class QTWORDREADERSHARED_EXPORT WordReader {
public:
    explicit WordReader(const QString& path);
    QString readAll();
private:
    QString m_path;
};


#endif //MYNOTES_WORDREADER_H
