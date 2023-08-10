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
    for (int i = -this->getPosition().x(); i < 8 - this->getPosition().x(); i++){
        if(checkOnOut(i, i))
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() + i]);
        if(checkOnOut(i, -i))
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() - i]);
    }

    for (int i = -this->getPosition().x(); i < 8 - this->getPosition().x(); i++){
        positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y()]);
    }

    for (int j = -this->getPosition().y(); j < 8 - this->getPosition().y(); j++){
        positions.push_back(vecOfBlocks[getPosition().x()][getPosition().y() + j]);
    }

    return positions;
}

void Queen::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
