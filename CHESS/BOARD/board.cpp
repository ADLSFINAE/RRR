#include "BOARD/board.h"
#include "FIGURES/elephant.h"
#include "FIGURES/horse.h"
#include "FIGURES/king.h"
#include "FIGURES/pawn.h"
#include "FIGURES/queen.h"
#include "FIGURES/rook.h"
Board::Board(QGraphicsScene *scene, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent), scene(scene)
{
    this->buildingBoard();
    this->figuresInitialization(true);
    this->figuresInitialization(false);
    allFigures += whiteFigures;
    allFigures += blackFigures;
    for(auto& figure : allFigures){
        figure->setFiguresVec(allFigures);
    }
    qDebug()<<whiteFigures.size()<<blackFigures.size()<<allFigures.size();
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
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

void Board::figuresInitialization(bool isWhite)
{
    int cols, pawnCols;
    isWhite ? ({cols = 7; pawnCols = 6;}) : ({cols = 0; pawnCols = 1;});

    QVector<Figure*>figuresTemp = {//ЗАПОЛНЕНИЕ ВРЕМЕННОГО
                                   new King(QPoint(4, cols), isWhite, vecOfBlocks),
                                   new Queen(QPoint(3, cols), isWhite, vecOfBlocks),
                                   new Horse(QPoint(1, cols), isWhite, vecOfBlocks),
                                   new Horse(QPoint(6, cols), isWhite, vecOfBlocks),
                                   new Elephant(QPoint(2, cols), isWhite, vecOfBlocks),
                                   new Elephant(QPoint(5, cols), isWhite, vecOfBlocks),
                                   new Rook(QPoint(0, cols), isWhite, vecOfBlocks),
                                   new Rook(QPoint(7, cols), isWhite, vecOfBlocks),
                                  };

    for(int rows = 0; rows < realX; rows++)
        figuresTemp.push_back(new Pawn(QPoint(rows, pawnCols), isWhite, vecOfBlocks));

    for (auto& figure : figuresTemp)
        scene->addItem(figure);

    for(auto& elem: figuresTemp){
        if(isWhite)
            whiteFigures.push_back(elem);
        else
            blackFigures.push_back(elem);
    }

}
