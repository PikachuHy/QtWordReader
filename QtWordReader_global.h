//
// Created by pikachu on 5/22/2021.
//

#ifndef QTWORDREADER_QTWORDREADER_GLOBAL_H
#define QTWORDREADER_QTWORDREADER_GLOBAL_H
#include <QtCore/qglobal.h>

#if defined(QtWordReader_LIBRARY)
#  define QTWORDREADERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTWORDREADERSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif //QTWORDREADER_QTWORDREADER_GLOBAL_H
