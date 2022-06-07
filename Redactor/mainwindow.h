#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "Reference.h"
#include "Redactor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Redactor *red_; //совместная работа с классом редактора
    Reference *Ref; //класс справки

    QString type_attack; //тип атаки
    QString FuncAttack; //фунция атаки

    int OCH; //кол во очков

    int _BuyDelay; //доп переменная сохраняющая изменения кол во очков
    int _BuyDuration; //иными словами это возможные изменения которые еще не повлияли
    int _BuyTypeAttack;

private slots:
    void on_CellBuy_clicked();
    void on_DistantionBuy_clicked();

    void update_Delay(double); //записываем установленное значение
    void update_Duration(double); //записываем установленное значение
    void updateMap(QString); //обновить карту
    void updateTypeAttack(QString); //обновить тип атаки
    void updateFuncAttack(QString); //обновить функцию атаки
    void UpdateCh(); //обновить зарактеристики

    void on_Create_clicked();//метод создания атаки (сохранение в xml виде)
    void on_Reference_triggered(); //открыть справку

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
