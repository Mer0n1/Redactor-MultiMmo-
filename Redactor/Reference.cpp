#include "Reference.h"
#include "ui_Reference.h"

Reference::Reference(QWidget *parent) :
    QDialog(parent), ui(new Ui::Reference)
{
    ui->setupUi(this);

    ui->verticalScrollBar->setMaximum(400);
QPushButton* tp1 = new QPushButton(this);
tp1->setGeometry(200, 100, 200, 100);
tp1->setText("Test");
tp1->setStyleSheet("color: rgb(85, 170, 255);border: none;");
    //Установка виджетов на evenFilter
    ui->tm1->installEventFilter(this);
    ui->tm1_1->installEventFilter(this);
    ui->tm1_2->installEventFilter(this);
    ui->tm1_3->installEventFilter(this);
    ui->tm2->installEventFilter(this);
    ui->tm2_1->installEventFilter(this);
    ui->tm2_2->installEventFilter(this);
    ui->tm3->installEventFilter(this);
    ui->tm3_1->installEventFilter(this);
    ui->tm3_2->installEventFilter(this);
    ui->tm3_3->installEventFilter(this);

    //загрузка текста из txt
    /*Основной идеей текста в редакторе стал стиль использующий разметки html.
    Таким образом мы не используем чистый html, и не используем css, это один
    из методов для удобности, однако не подразумевает универсальность */

    QFile fileTxt("save/Reference");
    fileTxt.open(QFile::ReadOnly | QFile::Text);

    QString data; //основной текст
    QFont font;

    while (!fileTxt.atEnd()) {
        QByteArray line = fileTxt.readLine();
        line += "<br>"; //добавляем пробелы
        data.append(line);
    }

    font.setPixelSize(12); //изменим размер текста

    ui->Text->setGeometry(10, 300, 500, 2000);
    ui->Text->setText(data);
    ui->Text->setFont(font);

    //загрузка видео
    playerDelay = new QMediaPlayer;
    playerDo = new QMediaPlayer;
    playerDuration = new QMediaPlayer;

    videoDelay = new QVideoWidget(this);
    videoDo = new QVideoWidget(this);
    videoDuration = new QVideoWidget(this);

    videoDuration->setGeometry(250, 1600, 208, 130); //(290, 1000, 160, 100)
    videoDelay->setGeometry(150, 1900, 240, 109); // 290, 1150, 200, 91
    videoDo->setGeometry(150, 860, 240, 114); //(290, 1300, 200, 95)

    videoDelay->setSizeIncrement(900,900);
    videoDo->setSizeIncrement(900,900);
    videoDuration->setSizeIncrement(900,900);

    playerDelay->setVideoOutput(videoDelay);
    playerDo->setVideoOutput(videoDo);
    playerDuration->setVideoOutput(videoDuration);

    videoDelay->show();
    videoDo->show();
    videoDuration->show();

    playerDelay->setMedia(QUrl("qrc:/img/Delay.avi"));
    playerDo->setMedia(QUrl("qrc:/img/Do.avi"));
    playerDuration->setMedia(QUrl("qrc:/img/Duration.avi"));

    playerDelay->play();
    playerDo->play();
    playerDuration->play();

    //-----------сигналы & слоты
    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateScroll(int))); //скроллинг
    //Обновление видео
    connect(playerDelay, &QMediaPlayer::stateChanged, [=]() { this->playerDelay->play(); } );
    connect(playerDo, &QMediaPlayer::stateChanged, [=]() { this->playerDo->play(); } );
    connect(playerDuration, &QMediaPlayer::stateChanged, [=]() { this->playerDuration->play(); } );
}

Reference::~Reference()
{
    delete ui;
}

bool Reference::eventFilter(QObject *o, QEvent *e)
{
    if ( !dynamic_cast<QInputEvent*>( e ) )
            return false;

    while ( o != NULL )
    {

        if(o == ui->tm1) { //Использование радактора тайлов

            if (e->type() == QEvent::MouseButtonPress)
                updateScroll(80); //при клике на кнопку скролим до нужной темы

            if (e->type() == QEvent::HoverEnter)
            { ui->tm1->setStyleSheet("color: rgb(85, 120, 255); border: none;"); return true; }
            else
            { ui->tm1->setStyleSheet("color: rgb(85, 170, 255); border: none;"); return true; }

        }

        if(o == ui->tm1_1) { //Очки
            if (e->type() == QEvent::MouseButtonPress)
                updateScroll(80); //при клике на кнопку скролим до нужной темы
        }

        if(o == ui->tm1_2) { //Размер карты
            if (e->type() == QEvent::MouseButtonPress)
                updateScroll(100); //при клике на кнопку скролим до нужной темы
        }

        o = o->parent();
    }
    return false;
}

void Reference::updateScroll(int d)
{
    int move = 5 * -d; //скорость скроллинга

    ui->Text->move(10, 300 + move); //пролистываем
    ui->Header->move(150, 10 + move);

    videoDelay->move(150, 1900 + move);
    videoDo->move(150, 860 + move);
    videoDuration->move(250, 1600 + move);

    ui->tm1->move(20, 40 + move);
    ui->tm1_1->move(50, 60 + move);
    ui->tm1_2->move(50, 80 + move);
    ui->tm1_3->move(50, 100 + move);
    ui->tm2->move(20, 130 + move);
    ui->tm2_1->move(50, 150 + move);
    ui->tm2_2->move(50, 170 + move);
    ui->tm3->move(20, 200 + move);
    ui->tm3_1->move(50, 220 + move);
    ui->tm3_2->move(50, 240 + move);
    ui->tm3_3->move(50, 260 + move);
}


void Reference::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8; //зададим размер насколько скроллить

    ui->verticalScrollBar->setValue(ui->verticalScrollBar->value() + numDegrees.y() * -1);
}
