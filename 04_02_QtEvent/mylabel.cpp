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

bool::MyLabel::event(QEvent *ev) {
    // 如果是鼠标按下，做事件拦截
    if(ev->type() == QEvent::MouseButtonPress) {
        QMouseEvent *ev = static_cast<QMouseEvent*>(ev);
        QString str = QString("event: mouse pressed x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        return true;
    }

    // 其他事件交给父类处理
    return QLabel::event(ev);
}

