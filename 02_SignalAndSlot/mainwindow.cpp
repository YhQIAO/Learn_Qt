#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 案例：下课后，老师发出饿了的信号，学生请老师吃饭
    // 创建老师学生对象
    this->teacher = new Teacher(this);
    this->student = new Student(this);

    // connect(teacher, &Teacher::hungry, student, &Student::treat);
    // 信号发生重载
    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry; // 声明一个函数指针
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(teacher, teacherSignal, student, studentSlot);
    ClassIsOver();

    // 点击按钮触发
    QPushButton* btn = new QPushButton("class over", this);
    btn->resize(200,100);
    // connect(btn,&QPushButton::clicked, this, &MainWindow::ClassIsOver);

    void(Teacher::*teacherSignal2)(void) = &Teacher::hungry;
    void(Student::*studentSlot2)(void) = &Student::treat;
    // 信号连接信号
    connect(teacher, teacherSignal2, student, studentSlot2);
    connect(btn,&QPushButton::clicked,teacher, teacherSignal2); // click不可以连接有参函数

    // 断开信号
    // disconnect(teacher, teacherSignal2, student, studentSlot2);

    /*
     * 信号可以连接信号
     * 信号可以连接多个槽函数
     * 多个信号可以连接多个槽函数
     * 信号和槽参数类型必须对应
     * 信号参数个数可以多于槽函数的个数
     */

    // qt4 版本的信号和槽的连接 优点直观，缺点类型不做检测
    connect(teacher, SIGNAL(hungry(QString)), student, SLOT(treat()));
    ClassIsOver();

    // C++ lambda 表达式
    [=]() {
        btn->setText("click me");
    }();

    QPushButton* btn2 = new QPushButton;
    btn2->setText("close window");
    btn2->setParent(this);
    btn2->resize(200,100);
    btn2->move(300,0);

    connect(btn2, &QPushButton::clicked, [=]() {
        this->close();
    });
}

void MainWindow::ClassIsOver(){
    emit teacher->hungry("KFC");
}

MainWindow::~MainWindow()
{
    delete ui;
}

