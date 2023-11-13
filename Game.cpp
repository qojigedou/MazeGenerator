#include "Game.h"


Game::Game(QWidget* parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1024, 768);
    QPixmap bgImage(":/images/bg4.png");
    scene->setBackgroundBrush(bgImage);
    setScene(scene);
}

void Game::start(){
    resMenu = new ResolutionMenu();
    resMenu->show();
    resMenu->displayResolutionMenu();
    close();

}

void Game::displayMainMenu(){
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Maze Generator"));
    QFont titleFont("comic sans", 50);
    titleText->setDefaultTextColor(QColorConstants::Svg::darkgreen);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("PLAY"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);



    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("QUIT"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);


}
