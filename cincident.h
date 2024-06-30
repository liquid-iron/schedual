#ifndef CINCIDENT_H
#define CINCIDENT_H
#include "QString"
#include <QDate>
class Cincident
{
public:
    Cincident();
    Cincident(QString name_,bool isimportant_,int year_,int month_,int day_,int ID_=0);
    QString name="";
    bool isimportant=0;
    int year=0;
    int month=0;
    int day=0;
    int ID=0;
};

#endif // CINCIDENT_H
