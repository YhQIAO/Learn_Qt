#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    // 槽函数可以写在public下 返回值void

signals:

public slots:
    void treat();
    void treat(QString foodname);


};

#endif // STUDENT_H
