#include "FIGURES/king.h"

King::King(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(":/chesscom/whiteFigures/wK.png"));
    else
        this->setPixmap(QPixmap(":/chesscom/blackFigures/bK.png"));
}

QVector<Block *> King::getValidNeighbourPositions()
{
    QVector<Block*> positions;
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if(checkOnOut(i, j))
                positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() + j]);
        }
    }

    return positions;
}

void King::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

void King::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void King::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
