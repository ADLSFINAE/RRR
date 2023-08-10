#include "elephant.h"

Elephant::Elephant(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteElephant));
    else
        this->setPixmap(QPixmap(pngBlackElephant));
}

QVector<Block *> Elephant::getValidNeighbourPositions()
{
    QVector<Block*> positions;
    for (int i = -this->getPosition().x(); i < 8 - this->getPosition().x(); i++){
        if(checkOnOut(i, i))
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() + i]);
        if(checkOnOut(i, -i))
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() - i]);
    }

    return positions;
}

void Elephant::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

