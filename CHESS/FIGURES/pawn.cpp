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
    qDebug()<<positions.size();
    getKnowledge(positions);
    qDebug()<<positions.size();
    return positions;
}

void Pawn::getKnowledge(QVector<Block *>& blockVec)
{
    QVector<Block*>forward;
    QVector<Block*>back;

    int current_figure_x = this->getPosition().x();
    int current_figure_y = this->getPosition().y();
    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X == current_figure_x && ELEM_Y > current_figure_y)
            forward.push_back(elem);
        if(ELEM_X == current_figure_x && ELEM_Y < current_figure_y)
            back.push_back(elem);
    }

    bubbleSortMaxToMinY(forward);
    bubbleSortMinToMaxY(back);

    removingUnnecessaryBlocks(forward);
    removingUnnecessaryBlocks(back);

    blockVec.clear();
    blockVec += forward;
    blockVec += back;
}

void Pawn::dungeonAndDragons(int offseX, int offseY)
{
    if(checkOnOut(offseX, offseY) &&
            vecOfBlocks[getPosition().x() + offseX][getPosition().y() + offseY]->getHavingFigure().first &&
            vecOfBlocks[getPosition().x() + offseX][getPosition().y() + offseY]->getHavingFigure().second != isWhite){
        vecOfBlocks[getPosition().x() + offseX][getPosition().y() + offseY]->setBrushColor(Qt::blue);
        this->addToPawnSoFunny(vecOfBlocks[getPosition().x() + offseX][getPosition().y() + offseY]);
    }
}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pawnSoFunny.clear();
    toClean.clear();
    toClean += getValidNeighbourPositions();
    for(auto& elem : toClean){
        elem->setBrushColor(Qt::yellow);
        if(elem->getHavingFigure().first && elem->getHavingFigure().second == this->isWhite)
            elem->setBrushColor(Qt::green);
        if(elem->getHavingFigure().first && elem->getHavingFigure().second != this->isWhite)
            elem->setBrushColor(elem->getDefBrush());
    }
    if(isWhite){
        dungeonAndDragons(1, -1);
        dungeonAndDragons(-1, -1);
    }
    else{
        dungeonAndDragons(1, 1);
        dungeonAndDragons(-1, 1);
    }
}

void Pawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
    for(auto& block : pawnSoFunny)
        block->setBrushColor(block->getDefBrush());
}

void Pawn::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
