#include "molecula.h"
#include <QPainter>
#define  X (this->pos().x())
#define  Y (this->pos().y())

molecula::molecula(float setX, float setY, QColor setColor,int speedX,int speedY)
{
    this->setPos(setX,setY);
    x=setX;
    y=setY;
    this->color=setColor;
    this->speed_x = speedX;
    this->speed_y = speedY;
    this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}
QRectF molecula::boundingRect() const
     {
         return QRectF(0,0,w,h);
     }
void molecula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
     {
         QPen pen(Qt::NoPen);
         QBrush brush(color);
         painter->setBrush(brush);
         painter->setPen(pen);
         painter->drawRect(0,0,w,h);
     }
void molecula::changePos()
{
    int msec =16;
    check();
    x+=speed_x*msec/1000;
    y+=speed_y*msec/1000;

    this->setPos(x,y);
}
void molecula::check()
{
    if(X>=330 || X <=0)
        speed_x*= -1;
    if(Y>=270 || Y <=0)
        speed_y*= -1;
    if(!(this->collidingItems().isEmpty()))
    {
        speed_x*=-1;
        speed_y*=-1;
    }
}
