#include "Maze.h"


Maze::Maze(int mazeWidth, int mazeHeight) : QGraphicsView()
{
    srand(QTime::currentTime().msec());


    const int pixels = Cell::tile;
    QGraphicsScene *s = new QGraphicsScene();
    s->setSceneRect(0, 0, mazeWidth*pixels, mazeHeight*pixels);
    s->setBackgroundBrush(QBrush(QColor(255, 255, 255), Qt::SolidPattern));
    setScene(s);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(mazeWidth*pixels, mazeHeight*pixels);

    grid.resize(mazeWidth);
    for (int i = 0; i < mazeWidth; ++i) {
        grid[i].resize(mazeHeight);
        for (int j = 0; j < mazeHeight; ++j) {
            grid[i][j] = new Cell(i, j, s);
        }
    }

    current_cell = grid[0][0];
    current_cell->setVisited();
    current_cell->mark();
    history.push(current_cell);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generate()));
    connect(timer, SIGNAL(timeout()), this, SLOT(start()));
    timer->start(speed);
}

void Maze::start()
{
    timer->start(speed);
}


void Maze::generate()
{
    next = getFreeNeighbour(current_cell);
    if(next != nullptr)
    {
        current_cell->unmark();
        next->mark();
        history.push(next);
        next->setVisited();
        removeWalls(current_cell, next);
        current_cell = next;
    }
    else if(!history.isEmpty())
    {
        current_cell->unmark();
        current_cell = history.pop();
        current_cell->mark();
    }
    else if(history.isEmpty())
    {

        timer->stop();
        current_cell->unmark();
    }
}

void Maze::removeWalls(Cell * current, Cell *next)
{
    int currentX, currentY, nextX, nextY;
    current->getIndexes(currentX, currentY);
    next->getIndexes(nextX, nextY);

    int diff[2] = {currentX - nextX, currentY - nextY};
    switch(diff[0])
    {
    case 1:
        current->left->hide();
        next->right->hide();
        break;
    case -1:
        current->right->hide();
        next->left->hide();
        break;
    }

    switch(diff[1])
    {
    case 1:
        current->top->hide();
        next->bottom->hide();
        break;
    case -1:
        current->bottom->hide();
        next->top->hide();
        break;
    }
}

Cell * Maze::getFreeNeighbour(Cell * curr)
{
    int curX, curY;
    QVector<Cell *> available;
    curr->getIndexes(curX, curY);

    if(curX > 0 && !grid[curX-1][curY]->isVisited()) //left
    {
        available.push_back(grid[curX-1][curY]);
    }
    if(curX < grid.size()-1 && !grid[curX+1][curY]->isVisited()) // right
    {
        available.push_back(grid[curX+1][curY]);
    }
    if(curY > 0 && !grid[curX][curY-1]->isVisited())
    {
        available.push_back(grid[curX][curY-1]);
    }
    if(curY < grid[curX].size()-1 && !grid[curX][curY+1]->isVisited())
    {
        available.push_back(grid[curX][curY+1]);
    }

    int len = available.size();
    if(len)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 100);
        int random_number = dis(gen);
        return available[random_number % len];
    }

    return nullptr;
}
