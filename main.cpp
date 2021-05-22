//
// Created by pikachu on 2021/4/13.
//
#include <QtWordReader>
#include <QDebug>
int main() {
    WordReader reader(R"(C:\Users\pikachu\Documents\研究学习\log\研一总结.docx)");
    auto ret = reader.readAll();
    qDebug().noquote() << ret;
    return 0;
}
