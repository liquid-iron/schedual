/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGroupBox *incident_groupBox;
    QPushButton *incident_add_pushButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *incident_verticalLayout;
    QListWidget *incident_listWidget;
    QHBoxLayout *incident_button_horizontalLayout;
    QPushButton *incident_edit_pushButton;
    QPushButton *incident_cancel_pushButton;
    QGroupBox *single_groupBox;
    QLabel *note_label;
    QPushButton *confirm_pushButton;
    QPushButton *cancel_pushButton;
    QWidget *incident_widget;
    QWidget *layoutWidget;
    QGridLayout *incident_gridLayout;
    QLineEdit *incident_name_lineEdit;
    QLabel *incident_date_label;
    QLabel *incident_important_label;
    QDateEdit *incident_date_Edit;
    QLabel *incident_name_label;
    QRadioButton *incident_important_radioButton;
    QWidget *task_widget;
    QWidget *layoutWidget1;
    QGridLayout *task_gridLayout;
    QLabel *task_date_label;
    QLabel *task_load_label;
    QDateEdit *task_date_Edit;
    QLabel *task_important_label;
    QSpinBox *task_load_spinBox;
    QLineEdit *task_name_lineEdit;
    QSpinBox *task_important_spinBox;
    QLabel *task_name_label;
    QPushButton *pushButton_2;
    QGroupBox *task_groupBox;
    QPushButton *task_add_pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *task_verticalLayout;
    QListWidget *task_listWidget;
    QHBoxLayout *task_horizontalLayout;
    QPushButton *task_edit_pushButton;
    QPushButton *task_cancel_pushButton;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(800, 600);
        incident_groupBox = new QGroupBox(MainWidget);
        incident_groupBox->setObjectName("incident_groupBox");
        incident_groupBox->setGeometry(QRect(5, 10, 250, 580));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(14);
        incident_groupBox->setFont(font);
        incident_add_pushButton = new QPushButton(incident_groupBox);
        incident_add_pushButton->setObjectName("incident_add_pushButton");
        incident_add_pushButton->setGeometry(QRect(200, 20, 41, 41));
        verticalLayoutWidget_2 = new QWidget(incident_groupBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 70, 231, 501));
        incident_verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        incident_verticalLayout->setObjectName("incident_verticalLayout");
        incident_verticalLayout->setContentsMargins(0, 0, 0, 0);
        incident_listWidget = new QListWidget(verticalLayoutWidget_2);
        incident_listWidget->setObjectName("incident_listWidget");

        incident_verticalLayout->addWidget(incident_listWidget);

        incident_button_horizontalLayout = new QHBoxLayout();
        incident_button_horizontalLayout->setObjectName("incident_button_horizontalLayout");
        incident_edit_pushButton = new QPushButton(verticalLayoutWidget_2);
        incident_edit_pushButton->setObjectName("incident_edit_pushButton");

        incident_button_horizontalLayout->addWidget(incident_edit_pushButton);

        incident_cancel_pushButton = new QPushButton(verticalLayoutWidget_2);
        incident_cancel_pushButton->setObjectName("incident_cancel_pushButton");

        incident_button_horizontalLayout->addWidget(incident_cancel_pushButton);


        incident_verticalLayout->addLayout(incident_button_horizontalLayout);

        single_groupBox = new QGroupBox(MainWidget);
        single_groupBox->setObjectName("single_groupBox");
        single_groupBox->setEnabled(true);
        single_groupBox->setGeometry(QRect(530, 10, 250, 580));
        single_groupBox->setFont(font);
        note_label = new QLabel(single_groupBox);
        note_label->setObjectName("note_label");
        note_label->setGeometry(QRect(30, 250, 191, 71));
        note_label->setFont(font);
        note_label->setAlignment(Qt::AlignCenter);
        confirm_pushButton = new QPushButton(single_groupBox);
        confirm_pushButton->setObjectName("confirm_pushButton");
        confirm_pushButton->setGeometry(QRect(40, 540, 91, 31));
        cancel_pushButton = new QPushButton(single_groupBox);
        cancel_pushButton->setObjectName("cancel_pushButton");
        cancel_pushButton->setGeometry(QRect(149, 540, 91, 31));
        incident_widget = new QWidget(single_groupBox);
        incident_widget->setObjectName("incident_widget");
        incident_widget->setGeometry(QRect(20, 80, 201, 171));
        layoutWidget = new QWidget(incident_widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 201, 171));
        incident_gridLayout = new QGridLayout(layoutWidget);
        incident_gridLayout->setObjectName("incident_gridLayout");
        incident_gridLayout->setContentsMargins(0, 0, 0, 0);
        incident_name_lineEdit = new QLineEdit(layoutWidget);
        incident_name_lineEdit->setObjectName("incident_name_lineEdit");
        incident_name_lineEdit->setEnabled(true);
        incident_name_lineEdit->setClearButtonEnabled(true);

        incident_gridLayout->addWidget(incident_name_lineEdit, 0, 1, 1, 1);

        incident_date_label = new QLabel(layoutWidget);
        incident_date_label->setObjectName("incident_date_label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font1.setPointSize(10);
        incident_date_label->setFont(font1);
        incident_date_label->setAlignment(Qt::AlignCenter);

        incident_gridLayout->addWidget(incident_date_label, 1, 0, 1, 1);

        incident_important_label = new QLabel(layoutWidget);
        incident_important_label->setObjectName("incident_important_label");
        incident_important_label->setEnabled(true);
        incident_important_label->setFont(font1);
        incident_important_label->setAlignment(Qt::AlignCenter);

        incident_gridLayout->addWidget(incident_important_label, 2, 0, 1, 1);

        incident_date_Edit = new QDateEdit(layoutWidget);
        incident_date_Edit->setObjectName("incident_date_Edit");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font2.setPointSize(9);
        incident_date_Edit->setFont(font2);

        incident_gridLayout->addWidget(incident_date_Edit, 1, 1, 1, 1);

        incident_name_label = new QLabel(layoutWidget);
        incident_name_label->setObjectName("incident_name_label");
        incident_name_label->setEnabled(true);
        incident_name_label->setFont(font1);
        incident_name_label->setAlignment(Qt::AlignCenter);

        incident_gridLayout->addWidget(incident_name_label, 0, 0, 1, 1);

        incident_important_radioButton = new QRadioButton(layoutWidget);
        incident_important_radioButton->setObjectName("incident_important_radioButton");

        incident_gridLayout->addWidget(incident_important_radioButton, 2, 1, 1, 1, Qt::AlignHCenter);

        task_widget = new QWidget(single_groupBox);
        task_widget->setObjectName("task_widget");
        task_widget->setGeometry(QRect(20, 80, 201, 201));
        layoutWidget1 = new QWidget(task_widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 201, 196));
        task_gridLayout = new QGridLayout(layoutWidget1);
        task_gridLayout->setObjectName("task_gridLayout");
        task_gridLayout->setContentsMargins(0, 0, 0, 0);
        task_date_label = new QLabel(layoutWidget1);
        task_date_label->setObjectName("task_date_label");
        task_date_label->setFont(font1);
        task_date_label->setAlignment(Qt::AlignCenter);

        task_gridLayout->addWidget(task_date_label, 1, 0, 1, 1);

        task_load_label = new QLabel(layoutWidget1);
        task_load_label->setObjectName("task_load_label");
        task_load_label->setEnabled(true);
        task_load_label->setFont(font1);
        task_load_label->setAlignment(Qt::AlignCenter);

        task_gridLayout->addWidget(task_load_label, 2, 0, 1, 1);

        task_date_Edit = new QDateEdit(layoutWidget1);
        task_date_Edit->setObjectName("task_date_Edit");
        task_date_Edit->setFont(font2);

        task_gridLayout->addWidget(task_date_Edit, 1, 1, 1, 1);

        task_important_label = new QLabel(layoutWidget1);
        task_important_label->setObjectName("task_important_label");
        task_important_label->setFont(font1);
        task_important_label->setAlignment(Qt::AlignCenter);

        task_gridLayout->addWidget(task_important_label, 3, 0, 1, 1);

        task_load_spinBox = new QSpinBox(layoutWidget1);
        task_load_spinBox->setObjectName("task_load_spinBox");

        task_gridLayout->addWidget(task_load_spinBox, 2, 1, 1, 1);

        task_name_lineEdit = new QLineEdit(layoutWidget1);
        task_name_lineEdit->setObjectName("task_name_lineEdit");
        task_name_lineEdit->setEnabled(true);
        task_name_lineEdit->setClearButtonEnabled(true);

        task_gridLayout->addWidget(task_name_lineEdit, 0, 1, 1, 1);

        task_important_spinBox = new QSpinBox(layoutWidget1);
        task_important_spinBox->setObjectName("task_important_spinBox");

        task_gridLayout->addWidget(task_important_spinBox, 3, 1, 1, 1);

        task_name_label = new QLabel(layoutWidget1);
        task_name_label->setObjectName("task_name_label");
        task_name_label->setEnabled(true);
        task_name_label->setFont(font1);
        task_name_label->setAlignment(Qt::AlignCenter);

        task_gridLayout->addWidget(task_name_label, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(single_groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 20, 71, 41));
        pushButton_2->setFont(font);
        task_groupBox = new QGroupBox(MainWidget);
        task_groupBox->setObjectName("task_groupBox");
        task_groupBox->setGeometry(QRect(270, 10, 250, 580));
        task_groupBox->setFont(font);
        task_add_pushButton = new QPushButton(task_groupBox);
        task_add_pushButton->setObjectName("task_add_pushButton");
        task_add_pushButton->setGeometry(QRect(200, 20, 41, 41));
        verticalLayoutWidget = new QWidget(task_groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 70, 231, 501));
        task_verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        task_verticalLayout->setObjectName("task_verticalLayout");
        task_verticalLayout->setContentsMargins(0, 0, 0, 0);
        task_listWidget = new QListWidget(verticalLayoutWidget);
        task_listWidget->setObjectName("task_listWidget");

        task_verticalLayout->addWidget(task_listWidget);

        task_horizontalLayout = new QHBoxLayout();
        task_horizontalLayout->setObjectName("task_horizontalLayout");
        task_edit_pushButton = new QPushButton(verticalLayoutWidget);
        task_edit_pushButton->setObjectName("task_edit_pushButton");

        task_horizontalLayout->addWidget(task_edit_pushButton);

        task_cancel_pushButton = new QPushButton(verticalLayoutWidget);
        task_cancel_pushButton->setObjectName("task_cancel_pushButton");

        task_horizontalLayout->addWidget(task_cancel_pushButton);


        task_verticalLayout->addLayout(task_horizontalLayout);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Schedual", nullptr));
        incident_groupBox->setTitle(QCoreApplication::translate("MainWidget", "\345\275\223\345\211\215\344\272\213\351\241\271", nullptr));
        incident_add_pushButton->setText(QCoreApplication::translate("MainWidget", "+", nullptr));
        incident_edit_pushButton->setText(QCoreApplication::translate("MainWidget", "\347\274\226\350\276\221", nullptr));
        incident_cancel_pushButton->setText(QCoreApplication::translate("MainWidget", "\345\210\240\351\231\244", nullptr));
        single_groupBox->setTitle(QCoreApplication::translate("MainWidget", "\347\274\226\350\276\221", nullptr));
        note_label->setText(QCoreApplication::translate("MainWidget", "\350\257\267\351\200\211\346\213\251/\346\226\260\345\273\272\344\270\200\344\270\252\351\241\271\347\233\256", nullptr));
        confirm_pushButton->setText(QCoreApplication::translate("MainWidget", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("MainWidget", "\345\217\226\346\266\210", nullptr));
        incident_date_label->setText(QCoreApplication::translate("MainWidget", "\346\210\252\350\207\263\346\227\266\351\227\264", nullptr));
        incident_important_label->setText(QCoreApplication::translate("MainWidget", "\351\207\215\350\246\201\344\272\213\344\273\266", nullptr));
        incident_name_label->setText(QCoreApplication::translate("MainWidget", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        incident_important_radioButton->setText(QCoreApplication::translate("MainWidget", "\351\207\215\350\246\201", nullptr));
        task_date_label->setText(QCoreApplication::translate("MainWidget", "\346\210\252\350\207\263\346\227\266\351\227\264", nullptr));
        task_load_label->setText(QCoreApplication::translate("MainWidget", "\346\200\273\344\273\273\345\212\241\351\207\217", nullptr));
        task_important_label->setText(QCoreApplication::translate("MainWidget", "\351\207\215\350\246\201\347\250\213\345\272\246", nullptr));
        task_name_label->setText(QCoreApplication::translate("MainWidget", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWidget", "\344\277\235\345\255\230", nullptr));
        task_groupBox->setTitle(QCoreApplication::translate("MainWidget", "\345\275\223\345\211\215\344\273\273\345\212\241", nullptr));
        task_add_pushButton->setText(QCoreApplication::translate("MainWidget", "+", nullptr));
        task_edit_pushButton->setText(QCoreApplication::translate("MainWidget", "\347\274\226\350\276\221", nullptr));
        task_cancel_pushButton->setText(QCoreApplication::translate("MainWidget", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
