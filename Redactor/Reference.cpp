#include "Reference.h"
#include "ui_Reference.h"

Reference::Reference(QWidget *parent) :
    QDialog(parent), ui(new Ui::Reference)
{
    ui->setupUi(this);

    ui->verticalScrollBar->setMaximum(400);

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

    videoDuration->setGeometry(150, 1650, 208, 130); //(290, 1000, 160, 100)
    videoDelay->setGeometry(150, 1950, 240, 109); // 290, 1150, 200, 91
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

//bool Reference::eventFilter(QObject *o, QEvent *e)
//{}

void Reference::updateScroll(int d)
{
    //создаем список всех ui элементов в форме
    QList<QWidget*> allWidget = Reference::findChildren<QWidget*>();
    static int b = d; //
    if (b > d) { b = d; d = -15; } else { b = d; d = 15;} //
    if (d == 0) d = -15;

       for (int j = 0; j < allWidget.size(); j++)
           if (allWidget[j] != ui->verticalScrollBar) //скролим все элементы кроме этого
           allWidget[j]->move(allWidget[j]->geometry().x(), allWidget[j]->geometry().y() + 5* -d);
}


void Reference::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8; //зададим размер на сколько скроллить

    ui->verticalScrollBar->setValue(ui->verticalScrollBar->value() + numDegrees.y() * -1);
}
