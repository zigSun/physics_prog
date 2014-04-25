#ifndef MOLECULA_H
#define MOLECULA_H

#include <QGraphicsItem>
#include <QColor>
class molecula : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit molecula(float setX,float setY,QColor setColor,int speedX,int speedY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

public slots:
    void changePos();
private:
    float x,y;
    int speed_x,speed_y;
    QColor color;
    const int w=3,h=3;
    void check();

};

#endif // MOLECULA_H
