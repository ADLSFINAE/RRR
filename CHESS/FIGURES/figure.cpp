#include "FIGURES/figure.h"

Figure::Figure(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks, QGraphicsPixmapItem *parent)
    :QGraphicsPixmapItem(parent), vecOfBlocks(vecOfBlocks), isWhite(isWhite), currPos(pos), startPos(pos)
{
    this->setOffset(0, 0);
    this->setPosition(currPos);
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    vecOfBlocks[this->getPosition().x()][this->getPosition().y()]->figureAboveBlockADD(this->isWhite);
}

void Figure::bubbleSortMinToMaxX(QVector<Block *>& vec)
{
    std::sort(vec.begin(), vec.end(),
              [&] (Block* block1, Block* block2) {return block1->getRealCoords().x() > block2->getRealCoords().x();});
}

void Figure::bubbleSortMaxToMinX(QVector<Block *>& vec)
{
    std::sort(vec.begin(), vec.end(),
              [&] (Block* block1, Block* block2) {return block1->getRealCoords().x() < block2->getRealCoords().x();});
}

void Figure::bubbleSortMinToMaxY(QVector<Block *>& vec)
{
    std::sort(vec.begin(), vec.end(),
              [&] (Block* block1, Block* block2) {return block1->getRealCoords().y() > block2->getRealCoords().y();});
}

void Figure::bubbleSortMaxToMinY(QVector<Block *>& vec)
{
    std::sort(vec.begin(), vec.end(),
              [&] (Block* block1, Block* block2) {return block1->getRealCoords().y() < block2->getRealCoords().y();});
}

void Figure::removingUnnecessaryBlocks(QVector<Block *> &vec)
{
    for(int i = 0; i < vec.size(); i++){
        if(vec[i]->getHavingFigure().first == true)
            vec.erase(vec.begin() + i + 1, vec.end());
    }
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
    toClean.clear();
    this->setOffset(0, 0);
    Q_UNUSED(event);
    toClean += getValidNeighbourPositions();
    for(auto& elem : toClean){
        elem->setBrushColor(Qt::yellow);
        if(elem->getHavingFigure().first && elem->getHavingFigure().second == this->isWhite)
            elem->setBrushColor(Qt::green);
        if(elem->getHavingFigure().first && elem->getHavingFigure().second != this->isWhite)
            elem->setBrushColor(Qt::blue);
    }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
#define CURR_BRUSH tempBlock->getCurrentBrush()
#define DEF_BRUSH tempBlock->getDefBrush()
#define TEAMMATE_BRUSH Qt::green
    this->setOffset(0, 0);

    QPair<Block*, double> toSetPos;
    toSetPos.first = vecOfBlocks[getPosition().x()][getPosition().y()];
    toSetPos.second = INT_MAX;

    for(auto& block : this->collidingItems()){
        Block* tempBlock = dynamic_cast<Block*>(block);
        if(tempBlock != nullptr && CURR_BRUSH != TEAMMATE_BRUSH){
            double calculateDistance = qSqrt(qPow(((int)mapToScene(event->pos()).x() - (int)tempBlock->pos().x() + 40), 2)
                                             + qPow(((int)mapToScene(event->pos()).x() - (int)tempBlock->pos().y() + 40), 2));
            if(toSetPos.second >= calculateDistance){
                toSetPos.first = tempBlock;
                toSetPos.second = calculateDistance;
            }
        }
    }
    for(auto & elem : getValidNeighbourPositions()){
        if(elem == toSetPos.first){
            this->setPosition(toSetPos.first->getRealCoords());
            for(auto& block : toClean){
                block->setBrushColor(block->getDefBrush());
            }
            break;
        }
    }
    this->setPosition(getPosition());

    for(auto& block : toClean){
        block->setBrushColor(block->getDefBrush());
    }

}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setOffset(-40, -40);
    this->setPos(mapToScene(event->pos()));
}
