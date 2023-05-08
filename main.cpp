#include <QMainWindow>
#include <QApplication>
#include "Maze.h"
#include "Button.h"
#include "Game.h"


Game* game;
int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();
    return app.exec();
}

