#ifndef QTASK_H
#define QTASK_H

#include <QWidget>
#include <ctask.h>
#include <QDate>
namespace Ui {
class Qtask;
}

class Qtask : public QWidget
{
    Q_OBJECT

public:
    explicit Qtask(QWidget *parent = nullptr);
    Qtask(Ctask t,QWidget *parent = nullptr);
    Ctask task;
    void updateNameLabel(QString a);
    ~Qtask();



private:
    Ui::Qtask *ui;
};

#endif // QTASK_H
