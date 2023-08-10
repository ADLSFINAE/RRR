#include "BOARD/block.h"
#include "qdebug.h"

Block::Block(QPoint pos, QBrush brush, QGraphicsRectItem* parent)
    :QGraphicsRectItem(parent), realCoords(pos), defBrush(brush)
{
    this->setRect(pos.x() * 80, pos.y() * 80, 80, 80);
    this->setBrush(defBrush);
    this->setPen(Qt::SolidLine);
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    this->isHaveFigure = false;
    this->isWhite = false;
}

void Block::setBrushColor(QBrush brush)
{
    this->currBrush = brush;
    this->setBrush(currBrush);
}

QPoint Block::getRealCoords() const
{
    return realCoords;
}

QBrush Block::getDefBrush() const
{
    return defBrush;
}

QBrush Block::getCurrentBrush() const
{
    return currBrush;
}

void Block::figureAboveBlockADD(bool isWhite)
{
    this->isHaveFigure = true;
    this->isWhite = isWhite;
}

void Block::figureAboveBlockDELETE()
{
    this->isHaveFigure = false;
}

QPair<bool, bool> Block::getHavingFigure()
{
    return {isHaveFigure, isWhite};
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsRectItem::mousePressEvent(event);
    qDebug()<<this->realCoords;
}

