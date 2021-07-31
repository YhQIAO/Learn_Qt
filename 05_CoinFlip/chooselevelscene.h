#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <playscene.h>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *ev);

private:
    PlayScene * play = NULL;

signals:
    // set a custom signal tell mainscene to return
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
