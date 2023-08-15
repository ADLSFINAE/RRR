#include "rook.h"

Rook::Rook(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks)
    :Figure(pos, isWhite, vecOfBlocks)
{
    if(isWhite)
        this->setPixmap(QPixmap(pngWhiteRook));
    else
        this->setPixmap(QPixmap(pngBlackRook));
}

QVector<Block *> Rook::getValidNeighbourPositions()
{
    QVector<Block*> positions;
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

QVector<Block*> Rook::getKnowledge(QVector<Block *> blockVec)
{

    QVector<Block*>forward;
    QVector<Block*>back;
    QVector<Block*>left;
    QVector<Block*>right;

    int current_figure_x = this->getPosition().x();
    int current_figure_y = this->getPosition().y();
    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X == current_figure_x && ELEM_Y >= current_figure_y)
            forward.push_back(elem);
        if(ELEM_X == current_figure_x && ELEM_Y <= current_figure_y)
            back.push_back(elem);
        if(ELEM_X < current_figure_x && ELEM_Y == current_figure_y)
            left.push_back(elem);
        if(ELEM_X > current_figure_x && ELEM_Y == current_figure_y)
            right.push_back(elem);
    }

    bubbleSortMaxToMinY(forward);
    bubbleSortMinToMaxY(back);
    bubbleSortMinToMaxX(left);
    bubbleSortMaxToMinX(right);

    removingUnnecessaryBlocks(forward);
    removingUnnecessaryBlocks(back);
    removingUnnecessaryBlocks(left);
    removingUnnecessaryBlocks(right);

    blockVec.clear();
    blockVec += forward;
    blockVec += back;
    blockVec += left;
    blockVec += right;

    return blockVec;
}

QVector<Block *> Rook::determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec)
{
    QVector<Block*>forward;
    QVector<Block*>back;
    QVector<Block*>left;
    QVector<Block*>right;

    int current_figure_x = this->getPosition().x();
    int current_figure_y = this->getPosition().y();
    for(auto& elem : blockVec){
#define ELEM_X elem->getRealCoords().x()
#define ELEM_Y elem->getRealCoords().y()
        if(ELEM_X == current_figure_x && ELEM_Y >= current_figure_y)
            forward.push_back(elem);
        if(ELEM_X == current_figure_x && ELEM_Y <= current_figure_y)
            back.push_back(elem);
        if(ELEM_X < current_figure_x && ELEM_Y == current_figure_y)
            left.push_back(elem);
        if(ELEM_X > current_figure_x && ELEM_Y == current_figure_y)
            right.push_back(elem);
    }

    bubbleSortMaxToMinY(forward);
    bubbleSortMinToMaxY(back);
    bubbleSortMinToMaxX(left);
    bubbleSortMaxToMinX(right);
    if(isWhite){
        if(searchKing(true, forward) && calculateFiguresCount(forward)){ return forward;};
        if(searchKing(true, back) && calculateFiguresCount(back)){return back;};
        if(searchKing(true, left) && calculateFiguresCount(left)){return left;};
        if(searchKing(true, right) && calculateFiguresCount(right)){return right;};
    }
    else{
        if(searchKing(false, forward) && calculateFiguresCount(forward)){return forward;};
        if(searchKing(false, back) && calculateFiguresCount(back)){return back;};
        if(searchKing(false, left) && calculateFiguresCount(left)){return left;};
        if(searchKing(false, right) && calculateFiguresCount(right)){return right;};
    }

    return {};
}

void Rook::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mousePressEvent(event);
}

void Rook::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseReleaseEvent(event);
}

void Rook::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Figure::mouseMoveEvent(event);
}
