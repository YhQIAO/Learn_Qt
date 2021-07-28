#include "mainwindow.h"

#include <QApplication>

// argc 命令行数 argv 变量数组
int main(int argc, char *argv[])
{

    // 应用程序对象 有且只有一个
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
