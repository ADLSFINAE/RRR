#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H
#include <QGraphicsScene>
#include "BOARD/board.h"

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CustomScene(QGraphicsScene* parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
private:
    Board* board{nullptr};
};

#endif // CUSTOMSCENE_H
