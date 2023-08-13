#ifndef QUEEN_H
#define QUEEN_H
#include "FIGURES/figure.h"

class Queen : public Figure
{
    Q_OBJECT
public:
    Queen(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // QUEEN_H
