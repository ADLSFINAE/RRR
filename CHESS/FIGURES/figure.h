#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
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

    void setFiguresVec(QVector<Figure*> vecOfFigures);

public:
    // Я И КОЛБАСНЫЕ ОБРЕЗКИ

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
public:
    QVector<QVector<Block*>> vecOfBlocks;
    QVector<Figure*> vecOfFigures;
    QVector<Block*> toClean;
    bool isWhite;
    QPoint currPos;
    QPoint startPos;
};

#endif // FIGURE_H
