#include "FIGURES/figure.h"

Figure::Figure(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks, QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem(parent), vecOfBlocks(vecOfBlocks), isWhite(isWhite), currPos(pos), startPos(pos)
{
    this->setOffset(0, 0);
    this->setPosition(currPos);
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    vecOfBlocks[this->getPosition().x()][this->getPosition().y()]->figureAboveBlockADD(this->isWhite);
    isClicked = false;
}

void Figure::setPosition(QPoint pos)
{
    vecOfBlocks[this->getPosition().x()][this->getPosition().y()]->figureAboveBlockDELETE();
    this->setPos(pos.x() * 80, pos.y() * 80);
    this->currPos = pos;
    vecOfBlocks[this->getPosition().x()][this->getPosition().y()]->figureAboveBlockADD(this->isWhite);
}

QPoint Figure::getPosition() const
{
    return currPos;
}

bool Figure::checkOnOut(int rows, int cols) const
{
    int sum_x = (this->getPosition().x() + rows);
    int sum_y = (this->getPosition().y() + cols);

    if((sum_x == getPosition().x()) &&(sum_y == getPosition().y()))
        return false;

    else if((sum_x >= 0) && (sum_x <= 7)
            && (sum_y >= 0) && (sum_y <= 7))
        return true;

    else
        return false;
}

void Figure::setFiguresVec(QVector<Figure *> vecOfFigures)
{
    this->vecOfFigures += vecOfFigures;
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    if(!isClicked){
        for(auto& elem : getValidNeighbourPositions()){
                elem->setBrushColor(Qt::yellow);
            if(elem->getHavingFigure().first && elem->getHavingFigure().second == this->isWhite)
                elem->setBrushColor(Qt::green);
            if(elem->getHavingFigure().first && elem->getHavingFigure().second != this->isWhite)
                elem->setBrushColor(Qt::blue);
        }
        isClicked = true;
        for(auto& elem : vecOfFigures){
            if(elem != this){
                elem->setEnabled(false);
            }
        }
    }
    else{
        for(auto& elem : getValidNeighbourPositions()){
            elem->setBrushColor(elem->getDefBrush());
        }
        isClicked = false;
        for(auto& elem : vecOfFigures){
            if(elem != this){
                elem->setEnabled(true);
            }
        }
    }
}
