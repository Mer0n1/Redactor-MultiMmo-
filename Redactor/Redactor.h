#ifndef REDACTOR_H
#define REDACTOR_H

#include <QDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMouseEvent>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <cmath>
#include <QVector2D>

QT_BEGIN_NAMESPACE
namespace Ui { class Redactor; }
QT_END_NAMESPACE

class Redactor : public QDialog
{
    Q_OBJECT
public:
    explicit Redactor(QWidget *parent = nullptr);
    ~Redactor();

    void setSizeTile(int size); //изменить размер тайлов (автоматически вызывает UpdateMap)
    void setDistance(int size); //установить дистанцию

    void RecordInFile(QXmlStreamWriter* xmlWriter); //записать в файл
private:
    void UpdateMap(); //обновить карту (обновить ее размеры тайлов или дистанцию)

    virtual void mousePressEvent(QMouseEvent* e); //обработка нажатий мыши
    virtual void keyPressEvent (QKeyEvent* e); //обработка нажатий клавиш

    QVector<QLabel*> vec;
    QLabel *ChPerson; //лейбл персонажа
    QWidget *red; //добавление через обьекты виджетов
    QPixmap person; //текстура модели персонажа
    int width, height; //высота ширина модельки персонажа

    int QuanTile; //макс допустимое кол во тайлов для выбора
    int distance; //зона от персонажа в пределах которой можно выбирать тайлы
    int SizeTile; //размер тайлов
    int recharge; //перезарядка (величина Атаки)
    int numC; //номер выделенного красным тайла в списке

    float delay[100]; //задержка тайла
    float duration[100]; //продолжительность кадра
    QVector2D redCo; //позиция выделенного красным цветом тайла
    QVector2D Tile[100]; //позиция выбранных тайлов

    Ui::Redactor *ui;
signals:
    void DUpdate(); //обновление характеристик при выборе тайла

    friend class MainWindow;
};


#endif // REDACTOR_H
