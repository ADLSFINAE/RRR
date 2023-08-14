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
    else if(!isWhite && this->getPosition().y() == 1){
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() + 1]);
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() + 2]);
    }
    else{
      if(isWhite){
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() - 1]);
      }
      else{
        positions.push_back(vecOfBlocks[this->getPosition().x()][this->getPosition().y() + 1]);
      }
    }
    return positions;
}

void Pawn::getKnowledge(QVector<Block *>& blockVec)
{

}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    toClean.clear();
    toClean += getValidNeighbourPositions();
    for(auto& elem : toClean){
        elem->setBrushColor(Qt::yellow);
        if(elem->getHavingFigure().first && elem->getHavingFigure().second == this->isWhite)
            elem->setBrushColor(Qt::green);
        if(elem->getHavingFigure().first && elem->getHavingFigure().second != this->isWhite)
            elem->setBrushColor(elem->getDefBrush());
    }
}

void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void Pawn::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
