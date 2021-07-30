#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标事件
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *ev) override;

    // 通过event事件分发器拦截鼠标按下事件
    bool event(QEvent *e);


signals:

};

#endif // MYLABEL_H
