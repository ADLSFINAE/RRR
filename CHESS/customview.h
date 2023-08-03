#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>

class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomView(QGraphicsScene* scene, QGraphicsView* parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};

#endif // CUSTOMVIEW_H
