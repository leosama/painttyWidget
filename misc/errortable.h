#ifndef ERRORTABLE_H
#define ERRORTABLE_H

#include <QString>
//#include <QObject>
//#include <QString>
//#include <unordered_map>

//class ErrorTable
//{
//public:
//    static QString toString(int errcode);
//private:
//    ErrorTable() Q_DECL_EQ_DELETE;
//    ~ErrorTable() Q_DECL_EQ_DELETE;
//    ErrorTable(const ErrorTable&) Q_DECL_EQ_DELETE;
//    ErrorTable& operator=(const ErrorTable&) Q_DECL_EQ_DELETE;
//    const static std::unordered_map<int, QString> errMsg_;
//};

namespace ErrorTable {
QString toString(int errorCode);
}

#endif // ERRORTABLE_H
