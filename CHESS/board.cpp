#include "board.h"
#include <QDebug>
Board::Board(QGraphicsScene *scene, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent), scene(scene)
{
    buildingBoard();
}

void Board::buildingBoard()
{
    scene->addItem(this);
    vecOfBlocks.resize(8);
    for(int i = 0; i < 8; i++){
        vecOfBlocks[i].resize(8);
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0)
                vecOfBlocks[i][j] = new Block(QPoint(i, j), Qt::white, this);
            else
                vecOfBlocks[i][j] = new Block(QPoint(i, j), Qt::black, this);
        }
    }
}
