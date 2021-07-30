#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // tablewidget useage

    // set col number
    ui->tableWidget->setColumnCount(3);
    // set header
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "name"<<"sex"<<"age");
    // set rows
    ui->tableWidget->setRowCount(5);
    // set item
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("xjy"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

