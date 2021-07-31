#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

PlayScene::PlayScene(int levelNum) {
    this->levelIndex = levelNum;
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("play scene");
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

    // show level num
    QLabel * label = new QLabel(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(8);
    QString str = QString("Level: %1").arg(this->levelIndex);
    label->setFont(font);
    label->setText(str);
    label->setGeometry(30, this->height()-50,120,50);
}

void PlayScene::paintEvent(QPaintEvent *ev){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(
                (this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);

}
