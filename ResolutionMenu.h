#include <QGraphicsView>
#include <QObject>
#include <QLineEdit>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QGraphicsProxyWidget>
#include <QPixmap>
#include "Maze.h"
#include "Button.h"

#ifndef RESOLUTIONMENU_H
#define RESOLUTIONMENU_H

class ResolutionMenu: public QGraphicsView{
    Q_OBJECT;
public:
    ResolutionMenu(QWidget* parent = nullptr);

    void displayResolutionMenu();

    QGraphicsScene* scene;
    Maze* maze;
    QLineEdit* widthInput;
    QLineEdit* heightInput;
    int mazeWidth, mazeHeight;

public slots:
    void startGame();
};
#endif // RESOLUTIONMENU_H
