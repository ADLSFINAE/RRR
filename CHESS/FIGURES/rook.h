#ifndef ROOK_H
#define ROOK_H
#include "FIGURES/figure.h"

class Rook : public Figure
{
    Q_OBJECT
public:
    Rook(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
public:
    QVector<Block*> getValidNeighbourPositions() override;
    QVector<Block*> getKnowledge(QVector<Block*> blockVec) override;
    QVector<Block *> determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // ROOK_H
