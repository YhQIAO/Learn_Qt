#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString filepath = QFileDialog::getOpenFileName(this, "open file", "C:\\Users\\97044\\Desktop");
        ui->lineEdit->setText(filepath);

        // 读取内容放入textEdit
        QTextCodec * codec = QTextCodec::codecForName("utf-8"); // 设置文本编码为utf-8

        QFile file(filepath);
        // set ways to open
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        ui->textEdit->setText(codec->toUnicode(array));
        file.close();

        QFileInfo info(filepath);
        qDebug() << info.size() << " " << info.suffix() << " " << info.fileName() << " " << info.path();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

