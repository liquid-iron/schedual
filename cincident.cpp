#include "cincident.h"

Cincident::Cincident() {}
Cincident::Cincident(QString name_,bool isimportant_,int year_,int month_,int day_,int ID_){
    name=name_;
    isimportant=isimportant_;
    year=year_;
    month=month_;
    day=day_;
    ID=ID_;
}
