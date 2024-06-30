#include "qtask.h"
#include "ui_qtask.h"

Qtask::Qtask(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Qtask)
{
    ui->setupUi(this);
    task=Ctask();

}
Qtask::Qtask(Ctask task_,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Qtask)
{
    ui->setupUi(this);
    task=task_;
    ui->name_label->setText(task.name);
    if(QDate(task.year,task.month,task.day).daysTo(QDate::currentDate())>=0){
        ui->name_label->setStyleSheet("QLabel { color : red; }");
    }
}
void Qtask::updateNameLabel(QString a) {
    ui->name_label->setText(a);
}
Qtask::~Qtask()
{
    delete ui;
}
