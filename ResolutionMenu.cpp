#include "ResolutionMenu.h"

ResolutionMenu::ResolutionMenu(QWidget* parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1024, 768);
    QPixmap bgImage(":/images/bg4.png");
    scene->setBackgroundBrush(bgImage);
    setScene(scene);
}

void ResolutionMenu::startGame(){
    mazeWidth = widthInput->text().toInt();
    mazeHeight = heightInput->text().toInt();
    Maze* maze = new Maze(mazeWidth, mazeHeight);
    maze->show();
    close();

}
void ResolutionMenu::displayResolutionMenu(){
    QGraphicsTextItem* titleResText = new QGraphicsTextItem(QString("Set the resolution"));
    QFont titleResFont("comic sans", 50);
    titleResText->setFont(titleResFont);
    titleResText->setDefaultTextColor(QColorConstants::Svg::darkgreen);
    int trxPos = this->width()/2 - titleResText->boundingRect().width()/2;
    int tryPos = 150;
    titleResText->setPos(trxPos, tryPos);
    scene->addItem(titleResText);


    Button* playButton = new Button(QString("PLAY"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 470;
    playButton->setPos(bxPos, byPos);

    connect(playButton, SIGNAL(clicked()), this, SLOT(startGame()));
    scene->addItem(playButton);

    QVBoxLayout* layout = new QVBoxLayout();

    widthInput = new QLineEdit();
    widthInput->setPlaceholderText("Number of rows");
    layout->addWidget(widthInput);

    heightInput = new QLineEdit();
    heightInput->setPlaceholderText("Number of columns");
    layout->addWidget(heightInput);

    QWidget* inputWidget = new QWidget();
    inputWidget->setLayout(layout);
    inputWidget->move(100, 200);
    inputWidget->resize(200, 100);

    QGraphicsProxyWidget* proxyWidget = scene->addWidget(inputWidget);
    proxyWidget->setPos(410, 300);

}
