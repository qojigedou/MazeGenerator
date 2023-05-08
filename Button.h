#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QGraphicsItem>

#ifndef BUTTON_H
#define BUTTON_H

class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Button(QString name, QGraphicsItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
