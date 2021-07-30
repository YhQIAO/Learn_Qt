#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem * item = new QListWidgetItem("123455");
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}

