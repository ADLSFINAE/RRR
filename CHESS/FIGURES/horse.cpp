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
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    for (int i = 0; i < 8; i++) {
        int newX = this->getPosition().x() + dx[i];
        int newY = this->getPosition().y() + dy[i];
        qDebug()<<newX<<newY;
        if(checkOnOut(dx[i], dy[i]))
            positions.push_back(vecOfBlocks[newX][newY]);
    }
    return positions;
}

void Horse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}
