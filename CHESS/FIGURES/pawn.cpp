#include "pawn.h"

Pawn::Pawn(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhitePawn));
    else
        this->setPixmap(QPixmap(pngBlackPawn));
}

QVector<Block *> Pawn::getValidNeighbourPositions()
{
    QVector<Block*> positions;

    return positions;
}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
