#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义信号 返回值void 只要声明
    void hungry();
    void hungry(QString foodname);

};

#endif // TEACHER_H
