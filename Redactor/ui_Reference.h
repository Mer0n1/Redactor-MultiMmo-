/********************************************************************************
** Form generated from reading UI file 'Reference.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFERENCE_H
#define UI_REFERENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QScrollBar *verticalScrollBar;
    QLabel *Text;
    QPushButton *tm1;
    QLabel *Header;
    QPushButton *tm1_1;
    QPushButton *tm1_2;
    QPushButton *tm1_3;
    QPushButton *tm2;
    QPushButton *tm2_1;
    QPushButton *tm2_2;
    QPushButton *tm3;
    QPushButton *tm3_1;
    QPushButton *tm3_2;
    QPushButton *tm3_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(517, 516);
        verticalScrollBar = new QScrollBar(Dialog);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(500, 10, 16, 501));
        verticalScrollBar->setMaximum(300);
        verticalScrollBar->setOrientation(Qt::Vertical);
        Text = new QLabel(Dialog);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(30, 290, 461, 301));
        tm1 = new QPushButton(Dialog);
        tm1->setObjectName(QString::fromUtf8("tm1"));
        tm1->setGeometry(QRect(20, 40, 181, 16));
        tm1->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        Header = new QLabel(Dialog);
        Header->setObjectName(QString::fromUtf8("Header"));
        Header->setGeometry(QRect(150, 10, 241, 21));
        Header->setStyleSheet(QString::fromUtf8(""));
        tm1_1 = new QPushButton(Dialog);
        tm1_1->setObjectName(QString::fromUtf8("tm1_1"));
        tm1_1->setGeometry(QRect(50, 60, 31, 20));
        tm1_1->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm1_2 = new QPushButton(Dialog);
        tm1_2->setObjectName(QString::fromUtf8("tm1_2"));
        tm1_2->setGeometry(QRect(50, 80, 81, 20));
        tm1_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm1_3 = new QPushButton(Dialog);
        tm1_3->setObjectName(QString::fromUtf8("tm1_3"));
        tm1_3->setGeometry(QRect(50, 100, 61, 20));
        tm1_3->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm2 = new QPushButton(Dialog);
        tm2->setObjectName(QString::fromUtf8("tm2"));
        tm2->setGeometry(QRect(20, 130, 91, 16));
        tm2->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm2_1 = new QPushButton(Dialog);
        tm2_1->setObjectName(QString::fromUtf8("tm2_1"));
        tm2_1->setGeometry(QRect(50, 150, 31, 16));
        tm2_1->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm2_2 = new QPushButton(Dialog);
        tm2_2->setObjectName(QString::fromUtf8("tm2_2"));
        tm2_2->setGeometry(QRect(50, 170, 41, 16));
        tm2_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm3 = new QPushButton(Dialog);
        tm3->setObjectName(QString::fromUtf8("tm3"));
        tm3->setGeometry(QRect(20, 200, 61, 16));
        tm3->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm3_1 = new QPushButton(Dialog);
        tm3_1->setObjectName(QString::fromUtf8("tm3_1"));
        tm3_1->setGeometry(QRect(50, 220, 16, 20));
        tm3_1->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm3_2 = new QPushButton(Dialog);
        tm3_2->setObjectName(QString::fromUtf8("tm3_2"));
        tm3_2->setGeometry(QRect(50, 240, 31, 20));
        tm3_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));
        tm3_3 = new QPushButton(Dialog);
        tm3_3->setObjectName(QString::fromUtf8("tm3_3"));
        tm3_3->setGeometry(QRect(50, 260, 21, 20));
        tm3_3->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"border: none;"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Text->setText(QString());
        tm1->setText(QCoreApplication::translate("Dialog", "\320\230\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200\320\260 \321\202\320\260\320\271\320\273\320\276\320\262", nullptr));
#if QT_CONFIG(tooltip)
        Header->setToolTip(QCoreApplication::translate("Dialog", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        Header->setWhatsThis(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-style:italic;\">\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200\320\260</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Header->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; font-style:italic;\">\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200\320\260</span></p></body></html>", nullptr));
        tm1_1->setText(QCoreApplication::translate("Dialog", "\320\236\321\207\320\272\320\270", nullptr));
        tm1_2->setText(QCoreApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\260\321\200\321\202\321\213", nullptr));
        tm1_3->setText(QCoreApplication::translate("Dialog", "\320\224\320\270\321\201\321\202\320\260\320\275\321\206\320\270\321\217", nullptr));
        tm2->setText(QCoreApplication::translate("Dialog", "\320\241\320\262\320\276\320\271\321\201\321\202\320\262\320\260 \320\260\321\202\320\260\320\272\320\270", nullptr));
        tm2_1->setText(QCoreApplication::translate("Dialog", "Delay", nullptr));
        tm2_2->setText(QCoreApplication::translate("Dialog", "Duration", nullptr));
        tm3->setText(QCoreApplication::translate("Dialog", "\320\242\320\270\320\277\321\213 \320\260\321\202\320\260\320\272\320\270", nullptr));
        tm3_1->setText(QCoreApplication::translate("Dialog", "Do", nullptr));
        tm3_2->setText(QCoreApplication::translate("Dialog", "Dpsa", nullptr));
        tm3_3->setText(QCoreApplication::translate("Dialog", "ida", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reference: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFERENCE_H
