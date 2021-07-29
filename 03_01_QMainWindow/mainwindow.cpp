#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,800);

    // 创建菜单栏 菜单栏最多只能有一个
    QMenuBar* bar = menuBar();
    setMenuBar(bar);

    // 创建菜单
    QMenu* FileMenu = bar->addMenu("File");
    QMenu* EditMenu = bar->addMenu("Edit");

    // 创建菜单项
    QAction* newAction = FileMenu->addAction("new file");
    // 添加分割线
    FileMenu->addSeparator();
    QAction* openAction = FileMenu->addAction("open file");

    // 工具栏 可以有多个
    QToolBar* toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar); // 设置工具栏在左边
    // 只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);

    // add action
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    // 添加一些控件
    QPushButton* btn = new QPushButton("aaa", this);
    toolBar->addWidget(btn);

    // 状态栏 最多只有一个
    QStatusBar* stBar = statusBar();
    setStatusBar(stBar);

    // 放置标签控件
    QLabel* label = new QLabel("message", this);
    stBar->addWidget(label);

    QLabel* label2 = new QLabel("message right", this);
    stBar->addPermanentWidget(label2);

    // 铆接部件（浮动窗口）
    QDockWidget* dockWigdet = new QDockWidget("a dock", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWigdet);
    dockWigdet->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // 设置中心控件，只能有一个
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

