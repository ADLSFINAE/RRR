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
    for (int i = -this->getPosition().x(); i < 8 - this->getPosition().x(); i++){
        if(i != 0)
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y()]);
    }

    for (int j = -this->getPosition().y(); j < 8 - this->getPosition().y(); j++){
        if(j != 0)
            positions.push_back(vecOfBlocks[getPosition().x()][getPosition().y() + j]);
    }
    return positions;
}

void Rook::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

void Rook::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void Rook::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
