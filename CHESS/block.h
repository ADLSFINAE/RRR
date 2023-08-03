#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QObject>
#include <QBrush>

class Block : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Block(QPoint pos, QBrush brush, QGraphicsRectItem* parent);
public:
    void setBrushColor(QBrush brush);// вызываем для смены цвета блока
public:
    //Геттеры для получения информации о блоке
    QPoint getRealCoords() const; //получить координаты на доске
    QBrush getDefBrush() const; // получить изначальный цвет блока
    QBrush getCurrentBrush() const;// получить текущий цвет блока
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    QPoint realCoords;
    QBrush defBrush;
    QBrush currBrush;

};

#endif // BLOCK_H
