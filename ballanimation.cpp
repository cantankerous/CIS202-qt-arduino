#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include<QDebug>


BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(0,0)),
    m_test(QPoint(100,100))

{
    setFixedSize(100,100);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = QPoint(5, 5);
}

void BallAnimation::addToOrigin(const QPoint &point)
{
    //if just switches direction, iplemnt the offset, then set just switched to false
    m_origin += QPoint(left_right,up_down);
    /*int ran_number = qrand() % 3;
qDebug()<<direction;
    double offsetter = 0;
    if (ran_number == 0)
        offsetter = -1;
    else if(ran_number == 1)
        offsetter = 0;
    else if(ran_number == 2)
        offsetter = 2;
 */
}

void BallAnimation::wall_detect()
{
    //if wall detected, invert x and y values     left_right,up_down   change these here thats all    setX() setY()
    if(m_origin.x() == 0+radius&&m_origin.y() == 0+radius)//top left corner
    {

    }
    else if(m_origin.x() == width()-radius&&m_origin.y() == 0+radius)//top right corner
    {

    }
    else if(m_origin.x() == 0+radius&&m_origin.y() == height()-radius)//bot left corner
    {


    }
    else if(m_origin.x() == width()-radius&&m_origin.y() == height()-radius)//bot right corner
    {
        left_right=-1;
        up_down=-1;
    }
    else if(m_origin.x() == 0+radius)//left side
    {
        left_right=1;
    }
    else if(m_origin.x() == width()-radius)//right side
    {
        left_right=-1;
        //set just switched to trye after we swap directions********************************
    }
    if(m_origin.y() == 0+radius)//top
    {

    }
    else if(m_origin.y() == height()-radius)//bottom
    {

    }
    else
        qDebug()<<"dog no wall";


}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width(),height()));//(dimesnions of the actualy widget)
    painter.drawRect(QRect(0+radius,0+radius,width()-radius*2,height()-radius*2));
    painter.setBrush(Qt::black);
    painter.setPen(Qt::white);
    painter.drawEllipse(m_origin,e_width,e_height);

}


