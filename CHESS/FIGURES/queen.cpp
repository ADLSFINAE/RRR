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
        if(i != 0)
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y()]);
    }

    for (int j = -this->getPosition().y(); j < 8 - this->getPosition().y(); j++){
        if(j != 0)
            positions.push_back(vecOfBlocks[getPosition().x()][getPosition().y() + j]);
    }
    return positions;
}

void Queen::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

void Queen::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void Queen::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
