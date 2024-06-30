#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QString>
#include "ctask.h"
#include "cincident.h"
#include "qtask.h"
#include "qincident.h"
#include "QDate"
#include <QListWidgetItem>
#include "QFile"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    Ctask task;
    int ALLtaskID;
    int taskID;
    Cincident incident;
    int ALLincidentID;
    int incidentID;
    bool istasknotincident;
    bool isnew;
    QList<Qtask*> tasks;
    QList<Qincident*> incidents;
    void sortTaskList();
    void sortIncidentList();


private slots:
    void on_task_add_pushButton_clicked();

    void on_incident_add_pushButton_clicked();

    void on_cancel_pushButton_clicked();

    void on_confirm_pushButton_clicked();

    void on_task_listWidget_itemClicked(QListWidgetItem *item);

    void on_incident_listWidget_itemClicked(QListWidgetItem *item);

    void on_task_edit_pushButton_clicked();

    void on_incident_edit_pushButton_clicked();

    void on_task_cancel_pushButton_clicked();

    void on_incident_cancel_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
