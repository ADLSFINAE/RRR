#include "horse.h"

Horse::Horse(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteHorse));
    else
        this->setPixmap(QPixmap(pngBlackHorse));
}

QVector<Block *> Horse::getValidNeighbourPositions()
{
    QVector<Block*> positions;

    return positions;
}

void Horse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
