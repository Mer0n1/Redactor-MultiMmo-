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
    void setQuanTile(int q); //установка значения количества допустимых тайлов
    void setRecharge(int q); //установка перезарядки
    void setActiveTile_Delay(int q); //установить задержку выделенному красным тайлу
    void setActiveTile_Duratuion(int q);//установить продолжительность выделенному красным тайлу

    int getDistance();
    int getSizeTile();
    int getQuanTile();
    int getRecharge();
    float getDelay(int number); //вернуть номер элемента массива задержки
    float getDuration(int number); //вернуть номер элемента массива продолжительности
    float getActiveTile_Duration(); //вернуть значение Duration выделенного красным тайла
    float getActiveTile_Delay();

    void RecordInFile(QXmlStreamWriter* xmlWriter); //записать в файл

private:
    void UpdateMap(); //обновить карту (обновить ее размеры тайлов)

    virtual void mousePressEvent(QMouseEvent* e); //обработка нажатий мыши
    virtual void keyPressEvent (QKeyEvent* e); //обработка нажатий клавиш


    QVector<QLabel*> vec;
    QLabel *ChPerson; //лейбл персонажа
    QWidget *red; //добавление через обьекты виджетов
    QPixmap person; //текстура модели персонажа
    QMouseEvent *EMouse; //настройки мышки
    int width, height; //высота ширина модельки персонажа

    int QuanTile; //макс допустимое кол во тайлов для выбора
    int distance; //зона от персонажа в пределах которой можно выбирать тайлы
    int recharge; //перезарядка (величина Атаки)
    int SizeTile; //размер тайлов
    int numC; //номер выделенного красным тайла в списке

    int Tile[100][2]; //позиция выбранных тайлов
    float delay[100]; //задержка тайла
    float duration[100]; //продолжительность кадра
    int redCo[2]; //позиция выделенного красным цветом тайла (0 - по x, 1 - по y)

    Ui::Redactor *ui;
signals:
    void DUpdate(); //обновление характеристик при выборе тайла
};


#endif // REDACTOR_H
