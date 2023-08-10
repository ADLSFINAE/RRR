#include "queen.h"

Queen::Queen(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteQueen));
    else
        this->setPixmap(QPixmap(pngBlackQueen));
}

QVector<Block *> Queen::getValidNeighbourPositions()
{
    QVector<Block*> positions;

    return positions;
}

void Queen::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
