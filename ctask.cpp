#include "ctask.h"
#include <cmath>

Ctask::Ctask(QString name_,int important_,int taskload_,int year_,int month_,int day_,int ID_){
    name=name_;
    important=important_;
    taskload=taskload_;
    year=year_;
    month=month_;
    day=day_;
    ID=ID_;

}
long long Ctask::getpriority(){
    QDate a= QDate(year,month,day);
    int days=a.daysTo(QDate::currentDate());

    if(days>0){
        return (1<<20)+important/(taskload+1);
    }
    return important*(taskload+1)/fmin((-days+1),100);
}
QDataStream &operator<<(QDataStream &out, const Ctask &task) {
    out << task.name << task.important << task.taskload << task.year << task.month << task.day << task.ID;
    return out;
}

QDataStream &operator>>(QDataStream &in, Ctask &task) {
    in >> task.name >> task.important >> task.taskload >> task.year >> task.month >> task.day >> task.ID;
    return in;
}
