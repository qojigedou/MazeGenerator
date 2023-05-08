#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QPainter>

#ifndef CELL_H
#define CELL_H

class Cell{
private:
    bool visited;
    int idx;
    int idy;
public:
    static const int tile = 10;
    QGraphicsLineItem *top;
    QGraphicsLineItem *right;
    QGraphicsLineItem *bottom;
    QGraphicsLineItem *left;
    QGraphicsRectItem *rect;


    Cell(int x, int y, QGraphicsScene *s);
    bool isVisited() const;
    void setVisited();
    void getIndexes(int &, int &) const;
    void mark();
    void unmark();
};


#endif // CELL_H
