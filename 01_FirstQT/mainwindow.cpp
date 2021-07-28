#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "mypushbutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // reset window size
    resize(600,400);
    // fix window size
    setFixedSize(600,400);

    QPushButton *btn = new QPushButton;
    // btn->show(); // 顶层方式弹出控件
    btn->setParent(this);
    btn->setText("a first btn");
    btn->resize(200,100);
    btn->move(100,100);

    // set title
    setWindowTitle("my first qt demo");

    MyPushButton *myBtn = new MyPushButton;
    myBtn->setText("mybtn");
    myBtn->setParent(this);
    myBtn->resize(200,100);

    // 点击按钮 关闭窗口
    connect(myBtn, &MyPushButton::clicked, this, &MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

