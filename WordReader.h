//
// Created by pikachu on 2021/4/13.
//

#ifndef MYNOTES_WORDREADER_H
#define MYNOTES_WORDREADER_H
#include <QString>
class WordReader {
public:
    explicit WordReader(const QString& path);
    QString readAll();
private:
    QString m_path;
};


#endif //MYNOTES_WORDREADER_H
