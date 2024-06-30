/********************************************************************************
** Form generated from reading UI file 'qincident.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QINCIDENT_H
#define UI_QINCIDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qincident
{
public:
    QLabel *name_label;

    void setupUi(QWidget *qincident)
    {
        if (qincident->objectName().isEmpty())
            qincident->setObjectName("qincident");
        qincident->resize(220, 60);
        name_label = new QLabel(qincident);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(10, 10, 201, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(14);
        name_label->setFont(font);
        name_label->setAlignment(Qt::AlignCenter);

        retranslateUi(qincident);

        QMetaObject::connectSlotsByName(qincident);
    } // setupUi

    void retranslateUi(QWidget *qincident)
    {
        qincident->setWindowTitle(QCoreApplication::translate("qincident", "Form", nullptr));
        name_label->setText(QCoreApplication::translate("qincident", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qincident: public Ui_qincident {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QINCIDENT_H
