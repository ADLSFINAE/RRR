#ifndef HORSE_H
#define HORSE_H
#include "FIGURES/figure.h"

class Horse : public Figure
{
    Q_OBJECT
public:
    Horse(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // HORSE_H
