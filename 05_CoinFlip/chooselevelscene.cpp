#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("choose level");

    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    QMenu  * startMenu = bar->addMenu("start");
    QAction* quitAction = startMenu->addAction("quit");
    connect(quitAction, &QAction::triggered,[=](){
        this->close();
    });

    MyPushButton * backBtn = new MyPushButton(
                ":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height()-backBtn->height());

    connect(backBtn, &MyPushButton::clicked, [=](){
        qDebug() << "press back button";
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSceneBack();
        });
    });

    // create level choose button
    for(int i = 0;i < 20; i++) {
        MyPushButton * menuButton = new MyPushButton(":/res/LevelIcon.png");
        menuButton->setParent(this);
        menuButton->move( i%4 *70+25, i/4 *70+135);

        connect(menuButton, &QPushButton::clicked, [=](){
            qDebug() << i;
            // enter play scene
            this->hide();
            play = new PlayScene(i+1);
            play->show();

            connect(play, &PlayScene::chooseSceneBack, [=](){
                this->show();
                delete play;
                play = NULL;
            });
        });

        QLabel * label = new QLabel(this);
        label->setFixedSize(menuButton->width(), menuButton->height());
        label->setText(QString::number(i));
        label->move(i%4 *70+25, i/4 *70+135);
        label->setAlignment(Qt::AlignCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *ev){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(
                (this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
