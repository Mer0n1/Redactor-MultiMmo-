/********************************************************************************
** Form generated from reading UI file 'Redactor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDACTOR_H
#define UI_REDACTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Redactor
{
public:

    void setupUi(QDialog *Redactor)
    {
        if (Redactor->objectName().isEmpty())
            Redactor->setObjectName(QString::fromUtf8("Redactor"));
        Redactor->resize(483, 464);


        retranslateUi(Redactor);

        QMetaObject::connectSlotsByName(Redactor);
    } // setupUi

    void retranslateUi(QDialog *Redactor)
    {
        Redactor->setWindowTitle(QCoreApplication::translate("Redactor", "Redactor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Redactor: public Ui_Redactor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDACTOR_H
