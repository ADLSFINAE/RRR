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
    if(isWhite && this->getPosition().y() == 6){
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() - 1]);
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() - 2]);
    }
    if(!isWhite && this->getPosition().y() == 1){
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() + 1]);
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() + 2]);
    }
    return positions;
}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
