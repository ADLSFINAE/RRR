#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "BOARD/block.h"
#include "STATEMENTS.h"
using namespace GlobVal;
class Figure : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Figure(QPoint pos, bool isWhite, QVector<QVector<Block*>>& vecOfBlocks, QGraphicsPixmapItem* parent = nullptr);
public:
    virtual QVector<Block*> getValidNeighbourPositions() = 0;
public:
    void setPosition(QPoint pos);
    QPoint getPosition() const;

    bool checkOnOut(int rows, int cols) const;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
public:
    QVector<QVector<Block*>> vecOfBlocks;
    bool isWhite;
    QPoint currPos;
    QPoint startPos;

    bool isClicked;
};

#endif // FIGURE_H
