#ifndef PAWN_H
#define PAWN_H
#include "FIGURES/figure.h"

class Pawn : public Figure
{
    Q_OBJECT
public:
    Pawn(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // PAWN_H