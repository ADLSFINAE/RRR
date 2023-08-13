#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "FIGURES/figure.h"

class Elephant : public Figure
{
    Q_OBJECT
public:
    Elephant(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // ELEPHANT_H
