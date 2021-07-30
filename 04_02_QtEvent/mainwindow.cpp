#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    QTimer *timer = new QTimer(this);
    timer->start(50);  // 每隔一段时间发出一个信号

    connect(timer, &QTimer::timeout,[=](){
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });

    // 点击暂停 停止定时器
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        timer->stop();
    });
}

void MainWindow::timerEvent(QTimerEvent *ev) {
    if(ev->timerId() == id1) {
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    if(ev->timerId() == id2){
        static int num = 1;
        ui->label_3->setText(QString::number(num++));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

