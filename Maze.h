#include <QtGlobal>
#include <QObject>
#include <QTime>
#include <QTimer>
#include <QStack>
#include <QThread>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <vector>
#include <random>
#include <cstdlib>
#include "Cell.h"

#ifndef MAZE_H
#define MAZE_H

class Maze : public QGraphicsView{
    Q_OBJECT;
public slots:
    void generate();
    void start();

public:
    Maze(int mazeWidth, int mazeHeight);
    Cell* getFreeNeighbour(Cell* current);
    void removeWalls(Cell* first, Cell* second);

    int mazeWidth;
    int mazeHeight;
    static const int speed = 100;
    std::vector<std::vector<Cell*>> grid;
    QStack<Cell *> history;
    Cell* current_cell = nullptr;
    Cell* next = nullptr;
    QTimer* timer;
};

#endif // MAZE_H
