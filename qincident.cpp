#include "qincident.h"
#include "ui_qincident.h"

Qincident::Qincident(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qincident)
{
    ui->setupUi(this);
}

Qincident::Qincident(Cincident incident_,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qincident)
{
    ui->setupUi(this);
    incident=incident_;
    ui->name_label->setText(incident.name);
    if(incident.isimportant==1){
        ui->name_label->setStyleSheet("QLabel { color : orange; }");
    }
    if(QDate(incident.year,incident.month,incident.day).daysTo(QDate::currentDate())>=0){
        ui->name_label->setStyleSheet("QLabel { color : red; }");
    }
}
void Qincident::updateNameLabel(QString a) {
    ui->name_label->setText(a);
}
Qincident::~Qincident()
{
    delete ui;
}
QDataStream &operator<<(QDataStream &out, const Cincident &incident) {
    out << incident.name << incident.isimportant << incident.year << incident.month << incident.day << incident.ID;
    return out;
}

QDataStream &operator>>(QDataStream &in, Cincident &incident) {
    in >> incident.name >> incident.isimportant >> incident.year >> incident.month >> incident.day >> incident.ID;
    return in;
}
