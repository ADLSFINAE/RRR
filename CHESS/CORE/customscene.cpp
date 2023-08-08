#include "CORE/customscene.h"
CustomScene::CustomScene(QGraphicsScene *parent)
    :QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, 640, 640);
    board = new Board(this);
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}
