/********************************************************************************
** Form generated from reading UI file 'qtask.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTASK_H
#define UI_QTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtask
{
public:
    QLabel *name_label;

    void setupUi(QWidget *Qtask)
    {
        if (Qtask->objectName().isEmpty())
            Qtask->setObjectName("Qtask");
        Qtask->resize(220, 60);
        name_label = new QLabel(Qtask);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(9, 9, 201, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(14);
        name_label->setFont(font);
        name_label->setAlignment(Qt::AlignCenter);

        retranslateUi(Qtask);

        QMetaObject::connectSlotsByName(Qtask);
    } // setupUi

    void retranslateUi(QWidget *Qtask)
    {
        Qtask->setWindowTitle(QCoreApplication::translate("Qtask", "Form", nullptr));
        name_label->setText(QCoreApplication::translate("Qtask", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qtask: public Ui_Qtask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTASK_H
