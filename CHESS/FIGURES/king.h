#ifndef KING_H
#define KING_H
#include <QPixmap>
#include "FIGURES/figure.h"

class King : public Figure
{
    Q_OBJECT
public:
    King(QPoint pos, bool isWhite, QVector<QVector<Block *> > &vecOfBlocks);
    QVector<Block*> getValidNeighbourPositions() override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // KING_H
