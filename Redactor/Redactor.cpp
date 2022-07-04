#include "Redactor.h"
#include "ui_Redactor.h"

Redactor::Redactor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Redactor)
{
    ui->setupUi(this);

    //Инициализация переменных
    for (int j = 0; j < 100; j++)
    for (int i = 0; i < 2; i++)
        Tile[j][i] = 0;

    for (int j = 0; j < 100; j++) {
        delay[j] = 0;
        duration[j] = 0;
    }

    QuanTile = 20;
    distance = 160;
    recharge = 30;
    SizeTile = 32;
    numC = 0;
    width = 70;
    height = 150;
    red = new QWidget;

    //карта
    for (int j = 0; j < 2789; j++)
        vec.push_back(new QLabel(this));

    setSizeTile(SizeTile); //редактируем размер карты

    //Персонаж
    person.load(":/new/prefix1/img/Developer.png");

    ChPerson = new QLabel(this);
    ChPerson->setPixmap(person.scaled(width, height, Qt::KeepAspectRatio));
    ChPerson->setGeometry(210, 170, width, height);
}

Redactor::~Redactor()
{
    delete ui;
    delete red;
    delete ChPerson;

    for (int j = 0; j < vec.size(); j++)
        delete vec[j];
}

void Redactor::mousePressEvent(QMouseEvent* e)
{

    if (e->buttons() == Qt::LeftButton)
    {

        QPixmap pixActive(":/new/prefix1/img/changeActive.png");
        QPixmap pix(":/new/prefix1/img/change.png");

        bool Block = false; //блок если щелчок идет за пределом допустимой дистанции
        if (e->pos().x() < ChPerson->x() - distance || //дистанция рассчитывается в тайлы
            e->pos().y() < ChPerson->y() - distance || //размером 32/32
            e->pos().x() > ChPerson->x() + 70 + distance ||
            e->pos().y() > ChPerson->y() + 150 + distance)
            Block = true;

        if(Block) return;

        //учитываем что у тайлов своя система координат, например 1 тайл по distance=160
        //будет равен x=0, y=0, а pos мыши будет выдавать координаты экрана/формы
        //Переводим высчитывая разницу между x0 и y0 в разных координатных системах
        float X = std::floor((e->pos().x() - vec[0]->pos().x()) / SizeTile);
        float Y = std::floor((e->pos().y() - vec[0]->pos().y()) / SizeTile);

        for (int q = 0; q < QuanTile; q++)
        if (Tile[q][0] == X && //если тайл уже активен отключаем его
            Tile[q][1] == Y && q != 0) {

            int numberVec = Tile[q][1] + Tile[q][0] * ((distance*2 + 150) / SizeTile); //номер тайла в векторе
            Tile[q][0] = 0; //сброс координат
            Tile[q][1] = 0;

            vec[numberVec]->setPixmap(pix.scaled(SizeTile, SizeTile, Qt::KeepAspectRatio)); //сброс текстуры

            for (int i = numberVec; i < QuanTile; i++) { //сдвиг
                Tile[q][0] = Tile[q+1][0];
                Tile[q][1] = Tile[q+1][1];
            }
            break;

        } else //если не активен выделяем тайл
            if (Tile[q][0] == 0 && Tile[q][1] == 0) {
            Tile[q][0] = X;
            Tile[q][1] = Y;
            vec[Tile[q][1] + Tile[q][0] * ((distance*2 + 150) / SizeTile)]->
                    setPixmap(pixActive.scaled(SizeTile, SizeTile, Qt::KeepAspectRatio)); //делаем тайл синим
            break;
       }
    }


    if (e->buttons() == Qt::RightButton) //правая кнопка мыши (или красное выделение)
    {
        QPixmap pixRed(":/new/prefix1/img/changeRed.png");
        QPixmap pixActive(":/new/prefix1/img/changeActive.png");

        //учитываем что у тайлов своя система координат, например 1 тайл по distance=160
        //будет равен x=0, y=0, а pos мыши будет выдавать координаты экрана/формы
        //Переводим высчитывая разницу между x0 и y0 в разных координатных системах
        float X = std::floor((e->pos().x() - vec[0]->pos().x()) / SizeTile);
        float Y = std::floor((e->pos().y() - vec[0]->pos().y()) / SizeTile);

        for (int n = 0; n < QuanTile; n++)
          if (Tile[n][0] == (int)X &&
              Tile[n][1] == (int)Y) //если такой тайл есть в списке
          {
              vec[Tile[numC][1] + Tile[numC][0] * ((distance*2 + 150) / SizeTile)]->
                      setPixmap(pixActive.scaled(SizeTile, SizeTile, Qt::KeepAspectRatio)); //если красное выделение уже есть убираем его у тайла

              vec[Tile[n][1] + Tile[n][0] * ((distance*2 + 150) / SizeTile)]->
                      setPixmap(pixRed.scaled(SizeTile, SizeTile, Qt::KeepAspectRatio)); //красим

              redCo[0] = Tile[n][0];
              redCo[1] = Tile[n][1];
              numC = n;
          }
        emit DUpdate(); //вызываем обновление характеристик
    }
}



void Redactor::keyPressEvent(QKeyEvent *e)
{

    //раздел перемещения карты
    if (e->key() == Qt::Key::Key_8)
    {
        for (int j = 0; j < vec.size(); j++)
            vec[j]->move(vec[j]->x(), vec[j]->y() + 10); //двигаем тайлы
        ChPerson->move(ChPerson->x(), ChPerson->y() + 10); //двигаем персонажа
    }
    if (e->key() == Qt::Key::Key_4)
    {
        for (int j = 0; j < vec.size(); j++)
            vec[j]->move(vec[j]->x() + 10, vec[j]->y());
        ChPerson->move(ChPerson->x() + 10, ChPerson->y());
    }
    if (e->key() == Qt::Key::Key_6)
    {
        for (int j = 0; j < vec.size(); j++)
            vec[j]->move(vec[j]->x() - 10, vec[j]->y());
        ChPerson->move(ChPerson->x() - 10, ChPerson->y());
    }
    if (e->key() == Qt::Key::Key_2)
    {
        for (int j = 0; j < vec.size(); j++)
            vec[j]->move(vec[j]->x(), vec[j]->y() - 10);
        ChPerson->move(ChPerson->x(), ChPerson->y() - 10);
    }
}

void Redactor::UpdateMap() //обновить карту (после какого то изменения)
{
    QPixmap pix(":/new/prefix1/img/change.png");

    for (int j = 0; j < vec.size(); j++) {
        vec[j]->setGeometry(0, 0, 0, 0); //сбрасываем перед изменением все тайлы
        vec[j]->setPixmap(pix.scaled(SizeTile, SizeTile, Qt::KeepAspectRatio)); //присваиваем им размер
    }

    int xD = (distance*2 + width) / SizeTile; //кол во тайлов по x и y учитывая макс допустимую дистанцию
    int yD = (distance*2 + height) / SizeTile;

    for (int x = 0; x < xD; x++)
    for (int y = 0; y < yD; y++)
        vec[y + x * yD]->setGeometry(210-distance + x * SizeTile, //делаем начало прорисовки чуть выше
                                     170-distance + y * SizeTile, SizeTile, SizeTile);
}

void Redactor::RecordInFile(QXmlStreamWriter* xmlWriter)
{
    //начало создания атаки
    int CurrentTile[100][2]; //Для дальнейшего изменения тайлов под другой обработчик

    for (int j = 0; j < QuanTile; j++)
                for (int c = 0; c < 2; c++)
                    CurrentTile[j][c] = Tile[j][c];

    for (int j = 0; j < QuanTile; j++) //переводим в координаты относительно центра
        if (CurrentTile[j][0] != 0 & CurrentTile[j][1] != 0) {

         int x1 = Tile[j][0] - ChPerson->x() / SizeTile;
         int y1 = Tile[j][1] - ChPerson->y() / SizeTile;

         CurrentTile[j][0] = x1;
         CurrentTile[j][1] = y1;
       }

    //delay
    xmlWriter->writeStartElement("delay"); //характеристика задержки

    QByteArray delay_;
    for (int j = 0; j < QuanTile; j++) {
        delay_.append(QString::number(delay[j]));
        delay_.append(" "); //добавляем пробел
    }

    xmlWriter->writeAttribute("Value", delay_);
    xmlWriter->writeEndElement(); //закрываем delay

    //duration
    xmlWriter->writeStartElement("duration"); //характеристика задержки

    QByteArray duration_;
    for (int j = 0; j < QuanTile; j++) {
        duration_.append(QString::number(duration[j]));
        duration_.append(" "); //добавляем пробел
    }

    xmlWriter->writeAttribute("Value", duration_);
    xmlWriter->writeEndElement(); //закрываем duration

    //Tile (тайлы)
    xmlWriter->writeStartElement("Tile");

    QByteArray TileX, TileY; //Переведем массив в побайтовый тип
    for (int j = 0; j < QuanTile; j++) {
        TileX.append(QString::number(CurrentTile[j][0]));
        TileX.append(" ");

        TileY.append(QString::number(CurrentTile[j][1]));
        TileY.append(" ");
    }

    xmlWriter->writeAttribute("ValueX", TileX);
    xmlWriter->writeAttribute("ValueY", TileY);
    xmlWriter->writeEndElement(); //закрываем Tile
}

void Redactor::setSizeTile(int size)
{
     SizeTile = size; //меняем размер карты
     UpdateMap(); //обновляем карту
}

void Redactor::setDistance(int size)
{
    distance = size;
    UpdateMap(); //обновляем карту
}
