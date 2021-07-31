#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret) {
        qDebug() << "load failed";
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoom1(){
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y(),this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y()+10,this->width(), this->height()+10));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::zoom2(){
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y()+10,this->width(), this->height()+10));
    animation->setEndValue(QRect(this->x(), this->y(),this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    // qDebug() << "pressed";
    if(this->pressImgPath != "") {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret) {
            qDebug() << "load failed";
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    // 让父类执行其他的内容
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(this->pressImgPath != "") {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret) {
            qDebug() << "load failed";
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    // 让父类执行其他的内容
    return QPushButton::mouseReleaseEvent(e);
}
