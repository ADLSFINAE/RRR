#include "figure.h"

Figure::Figure(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks, QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem(parent), vecOfBlocks(vecOfBlocks), isWhite(isWhite), currPos(pos), startPos(pos)
{
    this->setOffset(0, 0);
    this->setPosition(currPos);
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

QRectF Figure::boundingRect() const
{
    if(this->offset() == QPointF(-40, -40))
        return QRectF(-40, -40, 80, 80);
    return QRectF(0, 0, 80, 80);
}

void Figure::setPosition(QPoint pos)
{
    this->setPos(pos.x() * 80, pos.y() * 80);
    this->currPos = pos;
}

QPoint Figure::getPosition() const
{
    return currPos;
}

bool Figure::checkOnOut(int rows, int cols) const
{
    int sum_x = (this->getPosition().x() + rows);
    int sum_y = (this->getPosition().y() + cols);

    if((sum_x == getPosition().x()) &&(sum_y == getPosition().y()))
        return false;

    else if((sum_x >= 0) && (sum_x <= 7)
            && (sum_y >= 0) && (sum_y <= 7))
        return true;

    else
        return false;
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    this->setOffset(0, 0);
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    this->setOffset(0, 0);
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setOffset(-40, -40);
    this->setPos(mapToScene(event->pos()));
}
