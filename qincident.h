#ifndef QINCIDENT_H
#define QINCIDENT_H

#include <QWidget>
#include <cincident.h>
#include <QDate>
namespace Ui {
class qincident;
}

class Qincident : public QWidget
{
    Q_OBJECT

public:
    explicit Qincident(QWidget *parent = nullptr);
    Qincident(Cincident t,QWidget *parent = nullptr);
    Cincident incident;
    void updateNameLabel(QString a);
    ~Qincident();


private:
    Ui::qincident *ui;
};
QDataStream &operator<<(QDataStream &out, const Cincident &incident);
QDataStream &operator>>(QDataStream &in, Cincident &incident);

#endif // QINCIDENT_H
