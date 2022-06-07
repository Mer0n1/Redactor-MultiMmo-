/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Reference;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QWidget *centralwidget;
    QComboBox *FuncAttack;
    QPushButton *Create;
    QDoubleSpinBox *DurationTile;
    QDoubleSpinBox *DelayTile;
    QLabel *DelayTailT;
    QLabel *DurationTileT;
    QLabel *DurationTileT_2;
    QLabel *DelayTileT;
    QLabel *TileQ;
    QLabel *QuanTileCout;
    QLabel *QuanDelayCout;
    QLabel *QuanDurationCout;
    QComboBox *SizeMap;
    QLabel *QuanOCH;
    QPushButton *CellBuy;
    QPushButton *DistantionBuy;
    QComboBox *TypeAttack;
    QLabel *TypeAttack_Text;
    QLabel *FuncAttack_Text;
    QLabel *SizeMap_Text;
    QLineEdit *InputName;
    QLabel *NameAttack;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 327);
        Reference = new QAction(MainWindow);
        Reference->setObjectName(QString::fromUtf8("Reference"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        FuncAttack = new QComboBox(centralwidget);
        FuncAttack->addItem(QString());
        FuncAttack->addItem(QString());
        FuncAttack->addItem(QString());
        FuncAttack->setObjectName(QString::fromUtf8("FuncAttack"));
        FuncAttack->setGeometry(QRect(300, 80, 141, 21));
        Create = new QPushButton(centralwidget);
        Create->setObjectName(QString::fromUtf8("Create"));
        Create->setGeometry(QRect(290, 230, 161, 51));
        DurationTile = new QDoubleSpinBox(centralwidget);
        DurationTile->setObjectName(QString::fromUtf8("DurationTile"));
        DurationTile->setGeometry(QRect(180, 260, 62, 22));
        DelayTile = new QDoubleSpinBox(centralwidget);
        DelayTile->setObjectName(QString::fromUtf8("DelayTile"));
        DelayTile->setGeometry(QRect(180, 220, 62, 22));
        DelayTailT = new QLabel(centralwidget);
        DelayTailT->setObjectName(QString::fromUtf8("DelayTailT"));
        DelayTailT->setGeometry(QRect(30, 220, 141, 31));
        DurationTileT = new QLabel(centralwidget);
        DurationTileT->setObjectName(QString::fromUtf8("DurationTileT"));
        DurationTileT->setGeometry(QRect(30, 260, 141, 21));
        DurationTileT_2 = new QLabel(centralwidget);
        DurationTileT_2->setObjectName(QString::fromUtf8("DurationTileT_2"));
        DurationTileT_2->setGeometry(QRect(30, 180, 211, 31));
        DelayTileT = new QLabel(centralwidget);
        DelayTileT->setObjectName(QString::fromUtf8("DelayTileT"));
        DelayTileT->setGeometry(QRect(30, 150, 181, 31));
        TileQ = new QLabel(centralwidget);
        TileQ->setObjectName(QString::fromUtf8("TileQ"));
        TileQ->setGeometry(QRect(30, 120, 171, 31));
        QuanTileCout = new QLabel(centralwidget);
        QuanTileCout->setObjectName(QString::fromUtf8("QuanTileCout"));
        QuanTileCout->setGeometry(QRect(220, 120, 61, 31));
        QuanDelayCout = new QLabel(centralwidget);
        QuanDelayCout->setObjectName(QString::fromUtf8("QuanDelayCout"));
        QuanDelayCout->setGeometry(QRect(220, 150, 61, 31));
        QuanDurationCout = new QLabel(centralwidget);
        QuanDurationCout->setObjectName(QString::fromUtf8("QuanDurationCout"));
        QuanDurationCout->setGeometry(QRect(220, 180, 61, 31));
        SizeMap = new QComboBox(centralwidget);
        SizeMap->addItem(QString());
        SizeMap->addItem(QString());
        SizeMap->addItem(QString());
        SizeMap->addItem(QString());
        SizeMap->addItem(QString());
        SizeMap->addItem(QString());
        SizeMap->setObjectName(QString::fromUtf8("SizeMap"));
        SizeMap->setGeometry(QRect(300, 30, 141, 21));
        QuanOCH = new QLabel(centralwidget);
        QuanOCH->setObjectName(QString::fromUtf8("QuanOCH"));
        QuanOCH->setGeometry(QRect(30, 80, 71, 31));
        CellBuy = new QPushButton(centralwidget);
        CellBuy->setObjectName(QString::fromUtf8("CellBuy"));
        CellBuy->setGeometry(QRect(30, 10, 231, 21));
        DistantionBuy = new QPushButton(centralwidget);
        DistantionBuy->setObjectName(QString::fromUtf8("DistantionBuy"));
        DistantionBuy->setGeometry(QRect(30, 40, 231, 21));
        TypeAttack = new QComboBox(centralwidget);
        TypeAttack->addItem(QString());
        TypeAttack->addItem(QString());
        TypeAttack->addItem(QString());
        TypeAttack->setObjectName(QString::fromUtf8("TypeAttack"));
        TypeAttack->setGeometry(QRect(300, 130, 141, 21));
        TypeAttack_Text = new QLabel(centralwidget);
        TypeAttack_Text->setObjectName(QString::fromUtf8("TypeAttack_Text"));
        TypeAttack_Text->setGeometry(QRect(300, 100, 121, 31));
        FuncAttack_Text = new QLabel(centralwidget);
        FuncAttack_Text->setObjectName(QString::fromUtf8("FuncAttack_Text"));
        FuncAttack_Text->setGeometry(QRect(300, 50, 121, 31));
        SizeMap_Text = new QLabel(centralwidget);
        SizeMap_Text->setObjectName(QString::fromUtf8("SizeMap_Text"));
        SizeMap_Text->setGeometry(QRect(300, 0, 121, 31));
        InputName = new QLineEdit(centralwidget);
        InputName->setObjectName(QString::fromUtf8("InputName"));
        InputName->setGeometry(QRect(340, 200, 113, 20));
        NameAttack = new QLabel(centralwidget);
        NameAttack->setObjectName(QString::fromUtf8("NameAttack"));
        NameAttack->setGeometry(QRect(290, 200, 41, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Reference);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Reference->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 2", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 3", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 1", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 2", nullptr));
        action_6->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 3", nullptr));
        action_7->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 4", nullptr));
        FuncAttack->setItemText(0, QCoreApplication::translate("MainWindow", "Fixed", nullptr));
        FuncAttack->setItemText(1, QCoreApplication::translate("MainWindow", "Direction", nullptr));
        FuncAttack->setItemText(2, QCoreApplication::translate("MainWindow", "ClickPlace", nullptr));

        Create->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        DelayTailT->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Delay \321\202\320\260\320\271\320\273\320\260</span></p></body></html>", nullptr));
        DurationTileT->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Duration \321\202\320\260\320\271\320\273\320\260</span></p></body></html>", nullptr));
        DurationTileT_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \321\202\320\260\320\271\320\273\320\260:</span></p></body></html>", nullptr));
        DelayTileT->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260 \321\202\320\260\320\271\320\273\320\260:</span></p></body></html>", nullptr));
        TileQ->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\276 \320\272\320\273\320\265\321\202\320\276\320\272</span></p></body></html>", nullptr));
        QuanTileCout->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">0</span></p></body></html>", nullptr));
        QuanDelayCout->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">0</span></p></body></html>", nullptr));
        QuanDurationCout->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">0</span></p></body></html>", nullptr));
        SizeMap->setItemText(0, QCoreApplication::translate("MainWindow", "32", nullptr));
        SizeMap->setItemText(1, QCoreApplication::translate("MainWindow", "64", nullptr));
        SizeMap->setItemText(2, QCoreApplication::translate("MainWindow", "24", nullptr));
        SizeMap->setItemText(3, QCoreApplication::translate("MainWindow", "16", nullptr));
        SizeMap->setItemText(4, QCoreApplication::translate("MainWindow", "8", nullptr));
        SizeMap->setItemText(5, QCoreApplication::translate("MainWindow", "4", nullptr));

        QuanOCH->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">10000 </span></p></body></html>", nullptr));
        CellBuy->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\271\320\273 - 500 \320\236", nullptr));
        DistantionBuy->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\321\201\321\202\320\260\320\275\321\206\320\270\321\217 1500 - 1 \320\272\320\273\320\265\321\202\320\272\320\260", nullptr));
        TypeAttack->setItemText(0, QCoreApplication::translate("MainWindow", "Do", nullptr));
        TypeAttack->setItemText(1, QCoreApplication::translate("MainWindow", "dpsa", nullptr));
        TypeAttack->setItemText(2, QCoreApplication::translate("MainWindow", "ida", nullptr));

        TypeAttack_Text->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\242\320\270\320\277 \320\260\321\202\320\260\320\272\320\270: </span></p></body></html>", nullptr));
        FuncAttack_Text->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\220\321\202\320\260\320\272\320\270:</span></p></body></html>", nullptr));
        SizeMap_Text->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\260\321\200\321\202\321\213:</span></p></body></html>", nullptr));
        NameAttack->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
