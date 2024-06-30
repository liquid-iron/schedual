#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QDebug"
#include "ui_qtask.h"
#include "qtask.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ALLtaskID=0;
    ALLincidentID=0;
    for(int i=0; i<ui->task_gridLayout->count(); i++)
    {
        ui->task_gridLayout->itemAt(i)->widget()->hide();
    }
    for(int i=0; i<ui->incident_gridLayout->count(); i++)
    {
        ui->incident_gridLayout->itemAt(i)->widget()->hide();
    }
    ui->cancel_pushButton->hide();
    ui->confirm_pushButton->hide();
    ui->incident_edit_pushButton->hide();
    ui->incident_cancel_pushButton->hide();
    ui->task_cancel_pushButton->hide();
    ui->task_edit_pushButton->hide();
    QFile filet("tasks.dat");
    if (!filet.open(QIODevice::ReadOnly)) {
        // 处理错误
        return;
    }

    QDataStream in(&filet);
    while (!in.atEnd()) {
        Ctask task;
        in >> task;
        Qtask* qtask = new Qtask(task, this);
        tasks.append(qtask);

        QListWidgetItem* item = new QListWidgetItem(ui->task_listWidget);
        item->setSizeHint(qtask->size());
        ui->task_listWidget->setItemWidget(item, qtask);
    }
    QFile file("incidents.dat");
    if (!file.open(QIODevice::ReadOnly)) {
        // 处理错误
        return;
    }

    QDataStream ini(&file);
    while (!ini.atEnd()) {
        Cincident incident;
        ini >> incident;
        Qincident* qincident = new Qincident(incident, this);
        incidents.append(qincident);

        QListWidgetItem* item = new QListWidgetItem(ui->incident_listWidget);
        item->setSizeHint(qincident->size());
        ui->incident_listWidget->setItemWidget(item, qincident);
    }
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_task_add_pushButton_clicked()
{
    isnew=1;
    istasknotincident=1;

    for(int i=0; i<ui->incident_gridLayout->count(); i++)
    {
        ui->incident_gridLayout->itemAt(i)->widget()->hide();
    }
    ui->note_label->hide();
    for(int i=0; i<ui->task_gridLayout->count(); i++)
    {
        ui->task_gridLayout->itemAt(i)->widget()->show();

    }
    ui->task_widget->raise();
    ui->cancel_pushButton->show();
    ui->confirm_pushButton->show();
}


void MainWidget::on_incident_add_pushButton_clicked()
{
    isnew=1;
    istasknotincident=0;
    for(int i=0; i<ui->task_gridLayout->count(); i++)
    {
        ui->task_gridLayout->itemAt(i)->widget()->hide();
    }
    ui->note_label->hide();
    for(int i=0; i<ui->incident_gridLayout->count(); i++)
    {
        ui->incident_gridLayout->itemAt(i)->widget()->show();

    }
    ui->incident_widget->raise();
    ui->cancel_pushButton->show();
    ui->confirm_pushButton->show();
}


void MainWidget::on_cancel_pushButton_clicked()
{
    for(int i=0; i<ui->task_gridLayout->count(); i++)
    {
        ui->task_gridLayout->itemAt(i)->widget()->hide();
    }
    for(int i=0; i<ui->incident_gridLayout->count(); i++)
    {
        ui->incident_gridLayout->itemAt(i)->widget()->hide();
    }
    ui->note_label->show();
    ui->cancel_pushButton->hide();
    ui->confirm_pushButton->hide();
}


void MainWidget::on_confirm_pushButton_clicked()
{
    if(istasknotincident){
        QDate date=ui->task_date_Edit->date();

        if(isnew){
            ALLtaskID++;
            Ctask newCTask = Ctask(ui->task_name_lineEdit->text(),ui->task_important_spinBox->value(),ui->task_load_spinBox->value(),date.year(),date.month(),date.day(),ALLtaskID);
            Qtask* newQTask =new Qtask(newCTask,this);
            tasks.append(newQTask);  // 将新的 Qtask 对象添加到 tasks 列表中

            QListWidgetItem* item = new QListWidgetItem(ui->task_listWidget);
            // qDebug()<<newQTask->size();
            item->setSizeHint(newQTask->size());  // 设置项的大小为 Qtask 的大小
            ui->task_listWidget->setItemWidget(item, newQTask);  // 将新的 Qtask 对象添加到 task_listwidget 中
            for(int i=0; i<ui->task_gridLayout->count(); i++)
            {
                ui->task_gridLayout->itemAt(i)->widget()->hide();
            }
            for(int i=0; i<ui->incident_gridLayout->count(); i++)
            {
                ui->incident_gridLayout->itemAt(i)->widget()->hide();
            }
            ui->note_label->show();
            ui->cancel_pushButton->hide();
            ui->confirm_pushButton->hide();
        }
        else{
            Ctask updatedCTask = Ctask(ui->task_name_lineEdit->text(),ui->task_important_spinBox->value(),ui->task_load_spinBox->value(),date.year(),date.month(),date.day(),taskID);

            // 遍历 tasks 列表，找到与 taskID 相同的 Qtask 对象，然后更新它的 Ctask 对象
            for (Qtask* qtask : tasks) {
                if (qtask->task.ID == taskID) {
                    qtask->task = updatedCTask;
                    // qDebug()<<qtask->task.name<<qtask->task.ID<<taskID;
                    break;
                }
            }
            task=updatedCTask;
            // 更新 task_listWidget 中的对应元素
            for(int i = 0; i < ui->task_listWidget->count(); ++i) {
                QListWidgetItem* item = ui->task_listWidget->item(i);
                Qtask* qtask = dynamic_cast<Qtask*>(ui->task_listWidget->itemWidget(item));
                if (qtask && qtask->task.ID == taskID) {
                    ui->task_listWidget->setItemWidget(item, qtask);
                    qtask->updateNameLabel(task.name);

                    ui->task_listWidget->update();

                    break;
                }
            }
            // qDebug()<<task.name;
            for(int i = 0; i < ui->task_listWidget->count(); ++i) {
                QListWidgetItem* item = ui->task_listWidget->item(i);
                Qtask* qtask = dynamic_cast<Qtask*>(ui->task_listWidget->itemWidget(item));
                if (qtask && qtask->task.ID == taskID) {
                    qtask->task = updatedCTask;
                    qtask->updateNameLabel(task.name);  // 更新界面
                    qtask->repaint();   // 强制立即重绘
                    break;
                }
            }

            for(int i=0; i<ui->task_gridLayout->count(); i++)
            {
                ui->task_gridLayout->itemAt(i)->widget()->hide();
            }
            for(int i=0; i<ui->incident_gridLayout->count(); i++)
            {
                ui->incident_gridLayout->itemAt(i)->widget()->hide();
            }
            ui->note_label->show();
            ui->cancel_pushButton->hide();
            ui->confirm_pushButton->hide();
        }
        sortTaskList();
    }
    else{
        QDate date=ui->incident_date_Edit->date();
        Cincident(ui->incident_name_lineEdit->text(),ui->incident_important_radioButton->isChecked(),date.year(),date.month(),date.day());
        if(isnew){
            ALLincidentID++;
            Cincident newIncident= Cincident(ui->incident_name_lineEdit->text(),ui->incident_important_radioButton->isChecked(),date.year(),date.month(),date.day(),ALLincidentID);

            Qincident* newQIncident =new Qincident(newIncident,this);
            incidents.append(newQIncident);

            QListWidgetItem* item = new QListWidgetItem(ui->incident_listWidget);
            // qDebug()<<newQIncident->size();
            item->setSizeHint(newQIncident->size());  // 设置项的大小为 Qincident 的大小
            ui->incident_listWidget->setItemWidget(item, newQIncident);  // 将新的 Qincident 对象添加到 incident_listwidget 中
            for(int i=0; i<ui->task_gridLayout->count(); i++)
            {
                ui->task_gridLayout->itemAt(i)->widget()->hide();
            }
            for(int i=0; i<ui->incident_gridLayout->count(); i++)
            {
                ui->incident_gridLayout->itemAt(i)->widget()->hide();
            }
            ui->note_label->show();
            ui->cancel_pushButton->hide();
            ui->confirm_pushButton->hide();
        }
        else{
            Cincident updatedCIncident = Cincident(ui->incident_name_lineEdit->text(),ui->incident_important_radioButton->isChecked(),date.year(),date.month(),date.day(),incidentID);


            // 遍历 incidents 列表，找到与 incidentID 相同的 Qincident 对象，然后更新它的 Cincident 对象
            for (Qincident* qincident : incidents) {
                if (qincident->incident.ID == incidentID) {
                    qincident->incident = updatedCIncident;
                    break;
                }
            }

            incident=updatedCIncident;
            // 更新 incident_listWidget 中的对应元素
            for(int i = 0; i < ui->incident_listWidget->count(); ++i) {
                QListWidgetItem* item = ui->incident_listWidget->item(i);
                Qincident* qincident = dynamic_cast<Qincident*>(ui->incident_listWidget->itemWidget(item));
                if (qincident && qincident->incident.ID == incidentID) {
                    qincident->incident = updatedCIncident;
                    qincident->updateNameLabel(incident.name);  // 更新界面
                    qincident->repaint();   // 强制立即重绘
                    break;
                }
            }
            for(int i=0; i<ui->task_gridLayout->count(); i++)
            {
                ui->task_gridLayout->itemAt(i)->widget()->hide();
            }
            for(int i=0; i<ui->incident_gridLayout->count(); i++)
            {
                ui->incident_gridLayout->itemAt(i)->widget()->hide();
            }
            ui->note_label->show();
            ui->cancel_pushButton->hide();
            ui->confirm_pushButton->hide();
        }
        sortIncidentList();
    }



}
void MainWidget::sortTaskList()
{
    // 使用 std::sort 对 tasks 列表进行排序
    // for (Qtask* qtask : tasks) {
    //     qDebug() << "ID: " << qtask->task.ID << ", Name: " << qtask->task.name<<qtask->task.getpriority();
    // }

    std::sort(tasks.begin(), tasks.end(),  [](Qtask*& a,Qtask*& b) {
        return a->task.getpriority() > b->task.getpriority();
    });

    // for (Qtask* qtask : tasks) {
    //     qDebug() << "ID: " << qtask->task.ID << ", Name: " << qtask->task.name<<qtask->task.getpriority();
    // }

}

void MainWidget::sortIncidentList()
{
    // 使用 std::sort 对 tasks 列表进行排序
    // for (Qincident* qincident : incidents) {
    //     qDebug() << "ID: " << qincident->incident.ID << ", Name: " << qincident->incident.name<<qincident->incident.isimportant;
    // }
    std::sort(incidents.begin(), incidents.end(),  [](Qincident*& a,Qincident*& b) {
        if(a->incident.isimportant==1&&b->incident.isimportant==0){
            return 1;
        }
        else if(a->incident.isimportant==0&&b->incident.isimportant==1){
            return 0;
        }
        else{
            if ((QDate(a->incident.year,a->incident.month,a->incident.day).daysTo(QDate::currentDate()))>(QDate(b->incident.year,a->incident.month,a->incident.day).daysTo(QDate::currentDate()))){
                    return 1;
                }
            else{
                return 0;
            }
        }
    });

    // for (Qincident* qincident : incidents) {
    //     qDebug() << "ID: " << qincident->incident.ID << ", Name: " << qincident->incident.name<<qincident->incident.isimportant;
    // }
}


void MainWidget::on_task_listWidget_itemClicked(QListWidgetItem *item)
{
    Qtask* selectedQTask = dynamic_cast<Qtask*>(ui->task_listWidget->itemWidget(item));
    if (selectedQTask) {
        // 将 Qtask 对应的 Ctask 复制到 selectedTask 中
        task = selectedQTask->task;
        taskID=task.ID;
    }
    ui->task_cancel_pushButton->show();
    ui->task_edit_pushButton->show();

}


void MainWidget::on_incident_listWidget_itemClicked(QListWidgetItem *item)
{
    Qincident* selectedQIncident = dynamic_cast<Qincident*>(ui->incident_listWidget->itemWidget(item));
    if (selectedQIncident) {
        // 将 Qincident 对应的 Cincident 复制到 selectedIncident 中
        incident = selectedQIncident->incident;
        incidentID=incident.ID;
    }
    ui->incident_cancel_pushButton->show();
    ui->incident_edit_pushButton->show();

}


void MainWidget::on_task_edit_pushButton_clicked()
{
    ui->task_name_lineEdit->setText(task.name);
    ui->task_important_spinBox->setValue(task.important);
    ui->task_load_spinBox->setValue(task.taskload);
    ui->task_date_Edit->setDate(QDate(task.year,task.month,task.day));

    // qDebug()<<task.ID;
    isnew=0;
    istasknotincident=1;

    for(int i=0; i<ui->incident_gridLayout->count(); i++)
    {
        ui->incident_gridLayout->itemAt(i)->widget()->hide();
    }
    ui->note_label->hide();
    for(int i=0; i<ui->task_gridLayout->count(); i++)
    {
        ui->task_gridLayout->itemAt(i)->widget()->show();

    }
    ui->task_widget->raise();
    ui->cancel_pushButton->show();
    ui->confirm_pushButton->show();
}


void MainWidget::on_incident_edit_pushButton_clicked()
{
    ui->incident_name_lineEdit->setText(incident.name);
    ui->incident_important_radioButton->setChecked(incident.isimportant);
    ui->incident_date_Edit->setDate(QDate(incident.year,incident.month,incident.day));

    // qDebug()<<incident.ID;
    isnew=0;
    istasknotincident=0;

    for(int i=0; i<ui->incident_gridLayout->count(); i++)
    {
        ui->incident_gridLayout->itemAt(i)->widget()->show();
    }
    ui->note_label->hide();
    for(int i=0; i<ui->task_gridLayout->count(); i++)
    {
        ui->task_gridLayout->itemAt(i)->widget()->hide();

    }
    ui->incident_widget->raise();
    ui->cancel_pushButton->show();
    ui->confirm_pushButton->show();
}





void MainWidget::on_task_cancel_pushButton_clicked()
{
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i]->task.ID == taskID) {

            tasks.removeAt(i);  // 从 tasks 列表中删除 Qtask 对象
            break;
        }
    }

    // 从 task_listWidget 中删除对应的元素
    for(int i = 0; i < ui->task_listWidget->count(); ++i) {
        QListWidgetItem* item = ui->task_listWidget->item(i);
        Qtask* qtask = dynamic_cast<Qtask*>(ui->task_listWidget->itemWidget(item));
        if (qtask && qtask->task.ID == taskID) {
            ui->task_listWidget->takeItem(i);
            ui->task_listWidget->removeItemWidget(item);  // 从 task_listWidget 中移除项
            delete item;  // 删除 QListWidgetItem 对象
            ui->task_listWidget->update();  // 更新 task_listWidget 的布局
            break;
        }
    }
    task=Ctask();
    taskID=0;
}



void MainWidget::on_incident_cancel_pushButton_clicked()
{
    for (int i = 0; i < incidents.size(); ++i) {
        if (incidents[i]->incident.ID == incidentID) {

            incidents.removeAt(i);  // 从 incidents 列表中删除 Qincident 对象
            break;
        }
    }

    // 从 incident_listWidget 中删除对应的元素
    for(int i = 0; i < ui->incident_listWidget->count(); ++i) {
        QListWidgetItem* item = ui->incident_listWidget->item(i);
        Qincident* qincident = dynamic_cast<Qincident*>(ui->incident_listWidget->itemWidget(item));
        if (qincident && qincident->incident.ID == incidentID) {
            ui->incident_listWidget->takeItem(i);
            ui->incident_listWidget->removeItemWidget(item);  // 从 incident_listWidget 中移除项
            delete item;  // 删除 QListWidgetItem 对象
            ui->incident_listWidget->update();  // 更新 incident_listWidget 的布局
            break;
        }
    }
    incident=Cincident();
    incidentID=0;
}





void MainWidget::on_pushButton_2_clicked()
{
    QFile filet("tasks.dat");
    if (!filet.open(QIODevice::WriteOnly)) {
        // 处理错误
        return;
    }

    QDataStream outt(&filet);
    for (Qtask* qtask : tasks) {
        outt << qtask->task;
    }
    filet.close();
    QFile filei("incidents.dat");
    if (!filei.open(QIODevice::WriteOnly)) {
        // 处理错误
        return;
    }

    QDataStream outi(&filei);
    for (Qincident* qincident : incidents) {
        outi << qincident->incident;
    }
}

