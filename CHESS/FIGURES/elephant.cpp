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

QVector<Block*> Elephant::getKnowledge(QVector<Block *> blockVec)
{
    QVector<Block*>upper_left;
    QVector<Block*>upper_right;
    QVector<Block*>down_left;
    QVector<Block*>down_right;

    int current_figure_x = this->getPosition().x();
    int current_figure_y = this->getPosition().y();
    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X <= current_figure_x && ELEM_Y <= current_figure_y)
            upper_left.push_back(elem);
        if(ELEM_X >= current_figure_x && ELEM_Y <= current_figure_y)
            upper_right.push_back(elem);
        if(ELEM_X <= current_figure_x && ELEM_Y >= current_figure_y)
            down_left.push_back(elem);
        if(ELEM_X >= current_figure_x && ELEM_Y >= current_figure_y)
            down_right.push_back(elem);
    }

    bubbleSortMinToMaxX(upper_left);
    bubbleSortMaxToMinX(upper_right);
    bubbleSortMinToMaxX(down_left);
    bubbleSortMaxToMinX(down_right);

    removingUnnecessaryBlocks(upper_left);
    removingUnnecessaryBlocks(upper_right);
    removingUnnecessaryBlocks(down_left);
    removingUnnecessaryBlocks(down_right);

    blockVec.clear();
    blockVec += upper_left;
    blockVec += upper_right;
    blockVec += down_left;
    blockVec += down_right;

    return blockVec;
}

QVector<Block *> Elephant::determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec)
{
    QVector<Block*>upper_left;
    QVector<Block*>upper_right;
    QVector<Block*>down_left;
    QVector<Block*>down_right;

    int current_figure_x = this->getPosition().x();
    int current_figure_y = this->getPosition().y();
    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X <= current_figure_x && ELEM_Y <= current_figure_y)
            upper_left.push_back(elem);
        if(ELEM_X >= current_figure_x && ELEM_Y <= current_figure_y)
            upper_right.push_back(elem);
        if(ELEM_X <= current_figure_x && ELEM_Y >= current_figure_y)
            down_left.push_back(elem);
        if(ELEM_X >= current_figure_x && ELEM_Y >= current_figure_y)
            down_right.push_back(elem);
    }

    bubbleSortMinToMaxX(upper_left);
    bubbleSortMaxToMinX(upper_right);
    bubbleSortMinToMaxX(down_left);
    bubbleSortMaxToMinX(down_right);

    if(isWhite){
        if(searchKing(true, upper_left) && calculateFiguresCount(upper_left)){ return upper_left;};
        if(searchKing(true, upper_right) && calculateFiguresCount(upper_right)){return upper_right;};
        if(searchKing(true, down_left) && calculateFiguresCount(down_left)){return down_left;};
        if(searchKing(true, down_right) && calculateFiguresCount(down_right)){return down_right;};
    }
    else{
        if(searchKing(false, upper_left) && calculateFiguresCount(upper_left)){ return upper_left;};
        if(searchKing(false, upper_right) && calculateFiguresCount(upper_right)){return upper_right;};
        if(searchKing(false, down_left) && calculateFiguresCount(down_left)){return down_left;};
        if(searchKing(false, down_right) && calculateFiguresCount(down_right)){return down_right;};
    }
    return {};
}

void Elephant::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

void Elephant::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void Elephant::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}

