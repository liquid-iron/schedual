#ifndef CTASK_H
#define CTASK_H
#include "QString"
#include <QDate>
class Ctask
{
public:

    Ctask(QString name_="",int important_=0,int taskload_=0,int year_=0,int month_=0,int day_=0,int ID_=0);
    QString name="";
    int important=0;
    int taskload=0;
    int year=0;
    int month=0;
    int day=0;
    int ID=0;
    long long getpriority();

};

QDataStream &operator<<(QDataStream &out, const Ctask &task);
QDataStream &operator>>(QDataStream &in, Ctask &task);
#endif // CTASK_H
