#ifndef ROOK_H
#define ROOK_H
#include "FIGURES/figure.h"

class Rook : public Figure
{
    Q_OBJECT
public:
    Rook(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // ROOK_H