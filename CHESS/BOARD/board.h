#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QVector>
#include <QGraphicsScene>
#include "BOARD/block.h"
#include "FIGURES/figure.h"
#include "STATEMENTS.h"
using namespace GlobVal;

class Board : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Board(QGraphicsScene* scene, QGraphicsRectItem* parent = nullptr);
private:
    void buildingBoard(); // построение доски
    void figuresInitialization(bool isWhite);
private:
    QVector<QVector<Block*>> vecOfBlocks;
    QGraphicsScene* scene{nullptr};

    QVector<Figure*> blackFigures;
    QVector<Figure*> whiteFigures;
    QVector<Figure*> allFigures;
};

#endif // BOARD_H
