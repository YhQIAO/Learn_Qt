#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat(){
    qDebug() << "treat teacher";
}

void Student::treat(QString foodname) {
    // QString -> char*
    qDebug() << "treat teacher " << foodname.toUtf8().data();
}
