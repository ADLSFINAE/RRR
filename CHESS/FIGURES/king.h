#ifndef KING_H
#define KING_H
#include "FIGURES/figure.h"

class King : public Figure
{
    Q_OBJECT
public:
    King(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
public:
    QVector<Block*> getValidNeighbourPositions() override;
    QVector<Block*> getKnowledge(QVector<Block*> blockVec) override;
    QVector<Block *> determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec) override;
private:
    void swapKingAndRook(bool isWhite, QVector<Figure*> figVec);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
private:
    bool isMovedFromStartPosition;
    QPoint spawnPosition;
};

#endif // KING_H
