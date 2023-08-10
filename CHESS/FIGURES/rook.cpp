#include "rook.h"

Rook::Rook(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteRook));
    else
        this->setPixmap(QPixmap(pngBlackRook));
}

QVector<Block *> Rook::getValidNeighbourPositions()
{
    QVector<Block*> positions;

    return positions;
}

void Rook::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
