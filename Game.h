#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QPalette>
#include <QGraphicsTextItem>
#include <QPixmap>
#include "Maze.h"
#include "ResolutionMenu.h"
#include "Button.h"

#ifndef GAME_H
#define GAME_H

class Game: public QGraphicsView{
    Q_OBJECT;
public:
    Game(QWidget* parent = nullptr);

    void displayMainMenu();

    QGraphicsScene* scene;
    ResolutionMenu* resMenu;
public slots:
    void start();
};

#endif // GAME_H
