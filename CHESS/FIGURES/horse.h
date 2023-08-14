#ifndef HORSE_H
#define HORSE_H
#include "FIGURES/figure.h"

class Horse : public Figure
{
    Q_OBJECT
public:
    Horse(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
    void getKnowledge(QVector<Block*>& blockVec) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // HORSE_H
