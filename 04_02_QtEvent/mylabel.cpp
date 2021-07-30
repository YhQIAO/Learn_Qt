#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event){
    qDebug() << "mouse enter";
}

void MyLabel::leaveEvent(QEvent *event){
    qDebug() << "mouse leave";
}

void::MyLabel::mousePressEvent(QMouseEvent *ev) {
     QString str = QString("mouse pressed x = %1 y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
}
