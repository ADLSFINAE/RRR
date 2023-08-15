#include "FIGURES/king.h"

King::King(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks), spawnPosition(pos)
{
    isMovedFromStartPosition = false;
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteKing));
    else
        this->setPixmap(QPixmap(pngBlackKing));
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

QVector<Block*> King::getKnowledge(QVector<Block *> blockVec)
{
    return blockVec;
}

QVector<Block *> King::determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec)
{

}

void King::swapKingAndRook(bool isWhite, QVector<Figure *> figVec)
{
    if(isWhite && this->getPosition() == QPoint(7, 4)){

    }
}

void King::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
    if(isWhite){
        /*QVector<Block*> thisVecs = this->getValidNeighbourPositions();
        thisVecs.push_back(vecOfBlocks[getPosition().x()][getPosition().y()]);
        for(auto& fig : vecBlackFigures){
            for(auto& thisblock : fig->getValidNeighbourPositions()){
                for(auto& block : thisVecs){
                    if(thisblock == block){
                        thisblock->setBrushColor(Qt::red);
                    }
                }
            }
        }*/
    }
    else{

    }
}

void King::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);

    if(!isMovedFromStartPosition && this->getPosition() != spawnPosition){
        isMovedFromStartPosition = true;
    }
}

void King::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
