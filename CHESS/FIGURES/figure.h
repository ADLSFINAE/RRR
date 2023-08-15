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
    virtual QVector<Block*> getKnowledge(QVector<Block*> blockVec) = 0;
    virtual QVector<Block *> determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec) = 0;
public:
    bool searchKing(bool isWhite, QVector<Block*>& blockVec);
    bool calculateFiguresCount(QVector<Block*>& blockVec);
    void bubbleSortMinToMaxX(QVector<Block*>& vec);
    void bubbleSortMaxToMinX(QVector<Block*>& vec);
    void bubbleSortMinToMaxY(QVector<Block*>& vec);
    void bubbleSortMaxToMinY(QVector<Block*>& vec);

    void removingUnnecessaryBlocks(QVector<Block*>& vec);
public:
    void setPosition(QPoint pos);
    QPoint getPosition() const;

    bool checkOnOut(int rows, int cols) const;

    void setWhiteFiguresVec(QVector<Figure*> vecOfFigures);
    void setBlackFiguresVec(QVector<Figure*> vecOfFigures);

    void addToPawnSoFunny(Block* fig);
public:
    // Я И КОЛБАСНЫЕ ОБРЕЗКИ

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
public:
    QVector<QVector<Block*>> vecOfBlocks;
    QVector<Figure*> vecWhiteFigures;
    QVector<Figure*> vecBlackFigures;
    QVector<Block*> toClean;
    QVector<Block*> pawnSoFunny;
    bool isWhite;
    QPoint currPos;
    QPoint startPos;
};

#endif // FIGURE_H
