#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // treeWidget useage
    ui->treeWidget->setHeaderLabels(QStringList() << "Heros" << "Introduction");
    QTreeWidgetItem *liitem = new QTreeWidgetItem(QStringList() << "tank");
    QTreeWidgetItem *liitem2 = new QTreeWidgetItem(QStringList() << "shooter");
    QTreeWidgetItem *liitem3 = new QTreeWidgetItem(QStringList() << "wizzard");
    // 添加顶层节点
    ui->treeWidget->addTopLevelItem(liitem);
    ui->treeWidget->addTopLevelItem(liitem2);
    ui->treeWidget->addTopLevelItem(liitem3);

    QTreeWidgetItem *l11 = new QTreeWidgetItem(QStringList() << "lianpo" << "123");
    QTreeWidgetItem *l12 = new QTreeWidgetItem(QStringList() << "baiqi" << "chaofeng");
    QTreeWidgetItem *l13 = new QTreeWidgetItem(QStringList() << "change" << "fatan");
    liitem->addChild(l11);
}

MainWindow::~MainWindow()
{
    delete ui;
}

