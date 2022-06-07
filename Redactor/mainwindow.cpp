#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    type_attack = "Do";
    FuncAttack = "Fixed";
    OCH = 10000;
    _BuyDelay = 0;
    _BuyDuration = 0;
    _BuyTypeAttack = 0;

    red_ = new Redactor;
    Ref = new Reference;

    ui->DelayTile->setMaximum(100);
    ui->DurationTile->setMaximum(100);
    ui->QuanTileCout->setText(QString::number(red_->getQuanTile()));

    connect(ui->SizeMap, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateMap(QString))); //изменяем размер карты
    connect(ui->TypeAttack, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateTypeAttack(QString)));
    connect(ui->FuncAttack, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateFuncAttack(QString)));

    connect(ui->DelayTile, SIGNAL(valueChanged(double)), this, SLOT(update_Delay(double))); //обновляем значение задержки
    connect(ui->DurationTile, SIGNAL(valueChanged(double)), this, SLOT(update_Duration(double))); //обновляем значение продолжительности

    connect(red_, SIGNAL(DUpdate()), this, SLOT(UpdateCh())); //обновление характеристик при выборе тайла
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CellBuy_clicked() //купить тайлы
{
    if (OCH >= 500) {
        red_->setQuanTile(red_->getQuanTile() + 1); //QuanTile++
        OCH -= 500;
        ui->QuanTileCout->setText(QString::number(red_->getQuanTile()));
        ui->QuanOCH->setText(QString::number(OCH));
        ui->QuanOCH->setStyleSheet("font-size:21px;"); //стандарт размер
    }
}

void MainWindow::on_DistantionBuy_clicked() //купить дистанцию
{
    if (OCH >= 1500) {
        red_->setDistance(red_->getDistance() + red_->getSizeTile());
        OCH -= 1500;
        ui->QuanOCH->setText(QString::number(OCH));
    }
}

void MainWindow::UpdateCh() //обновить показ характеристик
{
     ui->QuanDelayCout->setNum(red_->getActiveTile_Delay());
     ui->QuanDurationCout->setNum(red_->getActiveTile_Duration()); //записываем в QLabel

     ui->DelayTile->setValue(red_->getActiveTile_Delay()); //записываем в ComboBox
     ui->DurationTile->setValue(red_->getActiveTile_Duration());

     ui->QuanOCH->setNum(OCH - _BuyDelay - _BuyDuration - _BuyTypeAttack);
     ui->QuanOCH->setStyleSheet("font-size:21px;"); //задаем прежний размер
}

void MainWindow::updateMap(QString size) //изменяем размеры карты
{
    red_->setSizeTile(size.toInt());
}

void MainWindow::updateTypeAttack(QString name)
{
    _BuyTypeAttack = 0;

    if (ui->TypeAttack->currentIndex() == 1) {
            if (OCH - _BuyDelay - _BuyDuration < 2000)
                ui->TypeAttack->setCurrentIndex(0); //если не хватает денег то возвращаемся к бесплатному
            else {
                _BuyTypeAttack = 2000; //если деньги есть то присваиваем значения
                type_attack = name;
            }
    }
    if (ui->TypeAttack->currentIndex() == 2) {
            if (OCH - _BuyDelay - _BuyDuration < 3000)
                ui->TypeAttack->setCurrentIndex(0); //если не хватает денег то возвращаемся к бесплатному
            else {
                _BuyTypeAttack = 3000; //если деньги есть то присваиваем значения
                type_attack = name;
            }
    }
    ui->QuanOCH->setText(QString::number(OCH - _BuyDelay - _BuyDuration - _BuyTypeAttack));
}

void MainWindow::updateFuncAttack(QString name)
{
    FuncAttack = name;
}

void MainWindow::update_Delay(double d)
{
    //записываем значение индекса в тот же индекс delay
    if (OCH >= 50) {
        red_->setActiveTile_Delay(d);
        _BuyDelay = 0;

        for (int j = 0; j < red_->getQuanTile(); j++)
            _BuyDelay += red_->getDelay(j) * 10 * 50; //берем значения со всех тайлов и суммируем их стоимость

        UpdateCh();
    }
}

void MainWindow::update_Duration(double d)
{
    //записываем значение индекса в тот же индекс duration
    if (OCH >= 100) {
        red_->setActiveTile_Duratuion(d);
        _BuyDuration = 0;

        for (int j = 0; j < red_->getQuanTile(); j++)
            _BuyDuration += red_->getDuration(j) * 10 * 50; //берем значения со всех тайлов и суммируем их стоимость

        UpdateCh();
    }
}

void MainWindow::on_Reference_triggered() //открыть справку
{
    Ref->show();
}

void MainWindow::on_Create_clicked() //создание атаки (запись в xml)
{

    if (ui->InputName->text() == "") { //выход если не указано название атаки
        QMessageBox::information(this, "Error", "Введите название атаки", QMessageBox::Ok);
        return;
    }

    if (OCH - _BuyDuration - _BuyDelay - _BuyTypeAttack < 0) { //выход если не хватает очков
        QMessageBox::information(this, "Error", "Недостает очков", QMessageBox::Ok);
        return ;
    }

    OCH -= _BuyDuration + _BuyDelay + _BuyTypeAttack; //минусуем очки

    //далее записываем в файл
    QFile file("save/SA.xml");
    file.open(QIODevice::ReadOnly | QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);  // Устанавливаем автоформатирование текста
    xmlWriter.writeStartDocument(); // Запускаем запись в документ

    xmlWriter.writeStartElement("account"); //аккаунт, место где будут храниться SA (атаки)
    xmlWriter.writeStartElement("SA"); //создаем атаку
    xmlWriter.writeAttribute("id", "1"); //даем номер атаки
    xmlWriter.writeAttribute("name", ui->InputName->text()); //даем название атаки

    red_->RecordInFile(&xmlWriter); //записываем внутренние переменные редактора

    //Description
    xmlWriter.writeStartElement("Description");
    xmlWriter.writeAttribute("FuncAttack", FuncAttack);
    xmlWriter.writeAttribute("TypeAttack", type_attack);
    xmlWriter.writeAttribute("Distantion", QString::number(red_->getDistance() / red_->getSizeTile()));
    xmlWriter.writeAttribute("Recharge", QString::number(red_->getRecharge()));
    xmlWriter.writeAttribute("QuanityTile", QString::number(red_->getQuanTile()));
    xmlWriter.writeAttribute("Size", QString::number(red_->getSizeTile()));
    xmlWriter.writeEndElement(); //закрываем Description

    //mobs
    xmlWriter.writeStartElement("mobs");
    xmlWriter.writeAttribute("Vide", "0");
    xmlWriter.writeAttribute("pVide", "0");
    xmlWriter.writeAttribute("tVide", "0");
    xmlWriter.writeEndElement(); //mobs

    xmlWriter.writeEndElement(); //закрываем SA
    xmlWriter.writeEndElement(); //закрываем account

    QMessageBox::information(this, "", "Attack created", QMessageBox::Ok);
}
