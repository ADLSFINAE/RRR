#include "queen.h"

Queen::Queen(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteQueen));
    else
        this->setPixmap(QPixmap(pngBlackQueen));
}

QVector<Block *> Queen::getValidNeighbourPositions()
{
    QVector<Block*> positions;
    for (int i = -this->getPosition().x(); i < 8 - this->getPosition().x(); i++){
        if(checkOnOut(i, i))
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() + i]);
        if(checkOnOut(i, -i))
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y() - i]);
    }

    for (int i = -this->getPosition().x(); i < 8 - this->getPosition().x(); i++){
        if(i != 0)
            positions.push_back(vecOfBlocks[getPosition().x() + i][getPosition().y()]);
    }

    for (int j = -this->getPosition().y(); j < 8 - this->getPosition().y(); j++){
        if(j != 0)
            positions.push_back(vecOfBlocks[getPosition().x()][getPosition().y() + j]);
    }

    return positions;
}

QVector<Block*> Queen::getKnowledge(QVector<Block *> blockVec)
{
    QVector<Block*>forward;
    QVector<Block*>back;
    QVector<Block*>left;
    QVector<Block*>right;
    QVector<Block*>upper_left;
    QVector<Block*>upper_right;
    QVector<Block*>down_left;
    QVector<Block*>down_right;

    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X == getPosition().x() && ELEM_Y >= getPosition().y()){
            forward.push_back(elem);
            continue;
        }
        if(ELEM_X == getPosition().x() && ELEM_Y <= getPosition().y()){
            back.push_back(elem);
            continue;
        }
        if(ELEM_X < getPosition().x() && ELEM_Y == getPosition().y()){
            left.push_back(elem);
            continue;
        }
        if(ELEM_X > getPosition().x() && ELEM_Y == getPosition().y()){
            right.push_back(elem);
            continue;
        }
        if(ELEM_X < getPosition().x() && ELEM_Y < getPosition().y()){
            upper_left.push_back(elem);
            continue;
        }
        if(ELEM_X > getPosition().x() && ELEM_Y < getPosition().y()){
            upper_right.push_back(elem);
            continue;
        }
        if(ELEM_X < getPosition().x() && ELEM_Y > getPosition().y()){
            down_left.push_back(elem);
            continue;
        }
        if(ELEM_X > getPosition().x() && ELEM_Y > getPosition().y()){
            down_right.push_back(elem);
            continue;
        }
    }


    bubbleSortMaxToMinY(forward);
    bubbleSortMinToMaxY(back);

    bubbleSortMinToMaxX(left);
    bubbleSortMaxToMinX(right);
    bubbleSortMinToMaxX(upper_left);
    bubbleSortMaxToMinX(upper_right);
    bubbleSortMinToMaxX(down_left);
    bubbleSortMaxToMinX(down_right);

    removingUnnecessaryBlocks(forward);
    removingUnnecessaryBlocks(back);
    removingUnnecessaryBlocks(left);
    removingUnnecessaryBlocks(right);
    removingUnnecessaryBlocks(upper_left);
    removingUnnecessaryBlocks(upper_right);
    removingUnnecessaryBlocks(down_left);
    removingUnnecessaryBlocks(down_right);

    blockVec.clear();
    blockVec += forward;
    blockVec += back;
    blockVec += left;
    blockVec += right;
    blockVec += upper_left;
    blockVec += upper_right;
    blockVec += down_left;
    blockVec += down_right;

    return blockVec;
}

QVector<Block *> Queen::determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec)
{
    QVector<Block*>forward;
    QVector<Block*>back;
    QVector<Block*>left;
    QVector<Block*>right;
    QVector<Block*>upper_left;
    QVector<Block*>upper_right;
    QVector<Block*>down_left;
    QVector<Block*>down_right;

    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X == getPosition().x() && ELEM_Y >= getPosition().y()){
            forward.push_back(elem);
            continue;
        }
        if(ELEM_X == getPosition().x() && ELEM_Y <= getPosition().y()){
            back.push_back(elem);
            continue;
        }
        if(ELEM_X < getPosition().x() && ELEM_Y == getPosition().y()){
            left.push_back(elem);
            continue;
        }
        if(ELEM_X > getPosition().x() && ELEM_Y == getPosition().y()){
            right.push_back(elem);
            continue;
        }
        if(ELEM_X < getPosition().x() && ELEM_Y < getPosition().y()){
            upper_left.push_back(elem);
            continue;
        }
        if(ELEM_X > getPosition().x() && ELEM_Y < getPosition().y()){
            upper_right.push_back(elem);
            continue;
        }
        if(ELEM_X < getPosition().x() && ELEM_Y > getPosition().y()){
            down_left.push_back(elem);
            continue;
        }
        if(ELEM_X > getPosition().x() && ELEM_Y > getPosition().y()){
            down_right.push_back(elem);
            continue;
        }
    }


    bubbleSortMaxToMinY(forward);
    bubbleSortMinToMaxY(back);

    bubbleSortMinToMaxX(left);
    bubbleSortMaxToMinX(right);
    bubbleSortMinToMaxX(upper_left);
    bubbleSortMaxToMinX(upper_right);
    bubbleSortMinToMaxX(down_left);
    bubbleSortMaxToMinX(down_right);

    if(isWhite){
        if(searchKing(true, forward) && calculateFiguresCount(forward)){ return forward;};
        if(searchKing(true, back) && calculateFiguresCount(back)){return back;};
        if(searchKing(true, left) && calculateFiguresCount(left)){return left;};
        if(searchKing(true, right) && calculateFiguresCount(right)){return right;};
        if(searchKing(true, upper_left) && calculateFiguresCount(upper_left)){ return upper_left;};
        if(searchKing(true, upper_right) && calculateFiguresCount(upper_right)){return upper_right;};
        if(searchKing(true, down_left) && calculateFiguresCount(down_left)){return down_left;};
        if(searchKing(true, down_right) && calculateFiguresCount(down_right)){return down_right;};
    }
    else{
        if(searchKing(false, forward) && calculateFiguresCount(forward)){return forward;};
        if(searchKing(false, back) && calculateFiguresCount(back)){return back;};
        if(searchKing(false, left) && calculateFiguresCount(left)){return left;};
        if(searchKing(false, right) && calculateFiguresCount(right)){return right;};
        if(searchKing(false, upper_left) && calculateFiguresCount(upper_left)){ return upper_left;};
        if(searchKing(false, upper_right) && calculateFiguresCount(upper_right)){return upper_right;};
        if(searchKing(false, down_left) && calculateFiguresCount(down_left)){return down_left;};
        if(searchKing(false, down_right) && calculateFiguresCount(down_right)){return down_right;};
    }
    return {};
}

void Queen::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

void Queen::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void Queen::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
