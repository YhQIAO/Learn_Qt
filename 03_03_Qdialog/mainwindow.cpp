#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建按钮弹出一个对话框
    connect(ui->actionnew, &QAction::triggered, [=](){
        // 对话框分类
        // 模态对话框 不可以对其他窗口进行操作
        // 非模态 可以对其他窗口进行操作
        // 模态对话框
//        QDialog dlg(this);
//        dlg.resize(200,200);
//        dlg.exec(); //阻塞

        // 非模态对话框
        QDialog *dlg2 = new QDialog(this);
        dlg2->show(); // 创建在堆区，存活
        dlg2->resize(200,200);
        // 主窗体不关闭，会一直创建新对象 不会释放
        dlg2->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭即释放
        qDebug() << "创建模态对话框";
    });

    connect(ui->actionopen, &QAction::triggered, [=](){
        // 错误对话框
        // QMessageBox::critical(this,"critical", "error");
        // 信息对话框
        // QMessageBox::information(this,"information","this is a message");
        // 提问对话框
        if(QMessageBox::No == QMessageBox::question(this,"question","is you a sb?",
                              QMessageBox::Yes|QMessageBox::No,
                              QMessageBox::No)){
            qDebug() << "click no";
        } else {
            qDebug() << "click yes";
        }
    });

    connect(ui->actionother, &QAction::triggered, [=]() {
        QString str = QFileDialog::getOpenFileName(this, "openFile","C:\\Users\\97044\\Desktop");
        qDebug() << str;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

