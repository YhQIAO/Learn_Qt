#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include "chooselevelscene.h"

#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    // 配置主场景
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("main scene of the game");

    chooseScene = new ChooseLevelScene;

    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });

    // add start button
    MyPushButton * startButton = new MyPushButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width()*0.5-startButton->width()*0.5, this->height()*0.7);

    // listen to the chooselevelScene's return signal
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this,[=](){
        chooseScene->hide();
        this->show();
    });

    // set start button's click animation
    connect(startButton, &MyPushButton::clicked, [=](){
        startButton->zoom1();
        startButton->zoom2();

        QTimer::singleShot(500, this, [=](){
            // enter choose leval scene
            this->hide();
            chooseScene->show();
        });
    });

}

void MainScene::paintEvent(QPaintEvent *ev) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    // pix = pix.scaled((int)(pix.width()*0,5), (int)(pix.height()*0.5));
    painter.drawPixmap(10,30,pix);

}

MainScene::~MainScene()
{
    delete ui;
}

