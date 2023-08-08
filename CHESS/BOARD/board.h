#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QVector>
#include <QGraphicsScene>
#include "block.h"

class Board : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Board(QGraphicsScene* scene, QGraphicsRectItem* parent = nullptr);
private:
    void buildingBoard(); // построение доски
private:
    QVector<QVector<Block*>> vecOfBlocks;
    QGraphicsScene* scene{nullptr};
};

#endif // BOARD_H
