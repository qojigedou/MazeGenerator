#include "Cell.h"

Cell::Cell(int x, int y, QGraphicsScene *scene)
{
    visited = false;
    idx = x;
    idy = y;
    x *= tile;
    y *= tile;

    rect = new QGraphicsRectItem(x,y,tile,tile); //for marking
    rect->setBrush(QBrush(QColor(0, 0, 255), Qt::SolidPattern));
    rect->setPen(Qt::NoPen);
    rect->hide();

    top = new QGraphicsLineItem (x, y, x+tile, y);
    right = new QGraphicsLineItem (x+tile, y, x+tile, y+tile);
    bottom = new QGraphicsLineItem (x, y+tile, x+tile, y+tile);
    left = new QGraphicsLineItem (x, y, x, y+tile);

    scene->addItem(top);
    scene->addItem(bottom);
    scene->addItem(left);
    scene->addItem(right);
    scene->addItem(rect);
}

bool Cell::isVisited() const
{
    return visited;
}

void Cell::setVisited()
{
    visited = true;
}

void Cell::getIndexes(int & x, int & y) const
{
    x = idx;
    y = idy;
}

void Cell::mark()
{
    rect->show();
}

void Cell::unmark()
{
    rect->hide();
}
