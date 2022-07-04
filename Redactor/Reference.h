#ifndef REFERENCE_H
#define REFERENCE_H

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QtMultimedia/QMediaPlayer>
#include <QVideoWidget>
#include <QWheelEvent>
#include <QPushButton>
#include <QPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class Reference; }
QT_END_NAMESPACE

class Reference : public QDialog //класс справки
{
    Q_OBJECT
public:
    Reference(QWidget *parent = nullptr);
    ~Reference();

private slots:
    void updateScroll(int); //изменяем значения координат скроллинга
    void wheelEvent(QWheelEvent *event); //скроллинг колесиком мышки
    //bool eventFilter(QObject *o, QEvent *e); //обработка событий QObject
private:
    QPointer<QMediaPlayer> playerDo; //плеер для проигрывания видео
    QPointer<QMediaPlayer> playerDuration;
    QPointer<QMediaPlayer> playerDelay;

    QPointer<QVideoWidget> videoDo;
    QPointer<QVideoWidget> videoDuration;
    QPointer<QVideoWidget> videoDelay;

    Ui::Reference *ui;
};


#endif // REFERENCE_H
