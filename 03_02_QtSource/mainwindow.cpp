#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 通过ui找到控件

    // 添加qt项目资源
    ui->actionnew->setIcon(QIcon(":/images/2021-01-23 (3).png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

