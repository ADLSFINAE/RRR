#ifndef QUEEN_H
#define QUEEN_H
#include "FIGURES/figure.h"

class Queen : public Figure
{
    Q_OBJECT
public:
    Queen(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
public:
    QVector<Block*> getValidNeighbourPositions() override;
    QVector<Block*> getKnowledge(QVector<Block*> blockVec) override;
    QVector<Block *> determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // QUEEN_H
