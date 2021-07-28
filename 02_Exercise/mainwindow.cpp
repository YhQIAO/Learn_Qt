#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mywindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /*
     * 实现如下功能：
     * 创建一个按钮，点击打开一个新窗体
     * 按钮的文本会随着窗体的打开或者关闭变化
     */

    ui->setupUi(this);
    myWindow = new MyWindow;

    QPushButton *btn = new QPushButton("open", this);
    btn->resize(200,100);
    connect(btn, &QPushButton::clicked,this, [=]() {
        if(btn->text() == "open") {
            myWindow->show();
            btn->setText("close");
        } else {
            myWindow->close();
            btn->setText("open");
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

