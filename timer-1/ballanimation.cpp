#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include<QDebug>


BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(50,0)),
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
        m_origin += QPoint(left_right,up_down);
}

void BallAnimation::wall_detect()
{
    if((   m_origin.x() == width()-radius&&m_origin.y() == height()-radius)//bot right corner
            || (m_origin.x() == radius&&m_origin.y() == height()-radius)//bot left corner
            || (m_origin.x() == width()-radius&&m_origin.y() == radius)//top right corner
            || (m_origin.x() == radius&&m_origin.y() == radius))//top left corner
    {
        left_right=-(left_right);//invert values
        up_down=-(up_down);
        just_switched = true;
    }

    else if(m_origin.x() == 0+radius)//left side
    {
        left_right=1;
        just_switched = true;
    }

    else if(m_origin.x() == width()-radius)//right side
    {
        left_right=-1;
        just_switched = true;
    }

    if(m_origin.y() == 0+radius)//top
    {
        up_down = 1;
        just_switched = true;
    }

    else if(m_origin.y() == height()-radius)//bottom
    {
        up_down = -1;
        just_switched = true;
    }

}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width(),height()));//(dimesnions of the actual widget)
    painter.drawRect(QRect(0+radius,0+radius,width()-radius*2,height()-radius*2));//smaller one?
    painter.setBrush(Qt::black);
    painter.setPen(Qt::white);
    painter.drawEllipse(m_origin,e_width,e_height);

}


