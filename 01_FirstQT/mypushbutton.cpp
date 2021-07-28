#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "mu btn diaoyong";
}

MyPushButton::~MyPushButton() {
    qDebug() << "my button xigou";
}
