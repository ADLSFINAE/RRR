#include "customview.h"

CustomView::CustomView(QGraphicsScene *scene, QGraphicsView *parent)
    :QGraphicsView(parent)
{
    this->setScene(scene);
    this->setFixedSize(648, 648);
}

void CustomView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void CustomView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void CustomView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}
