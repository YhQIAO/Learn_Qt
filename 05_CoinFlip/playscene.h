#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levalNum);
    int levelIndex;
    void paintEvent(QPaintEvent *ev);

signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
