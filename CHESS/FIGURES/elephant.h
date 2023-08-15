#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "FIGURES/figure.h"

class Elephant : public Figure
{
    Q_OBJECT
public:
    Elephant(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
public:
    QVector<Block *> getValidNeighbourPositions() override;
    QVector<Block *> getKnowledge(QVector<Block*> blockVec) override;
    QVector<Block *> determinationOfPositionsDangerousForTheKing(QVector<Block *> blockVec) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // ELEPHANT_H
