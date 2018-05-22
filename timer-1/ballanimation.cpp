#include "ballanimation.h"
#include <QDebug>
#include<QPaintEvent>
#include<QPainter>
BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(50,50))
{
    setFixedSize(200,200);
}
void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = orogin;
}
void BallAnimation::addToOrigin(const QPoint &point)
{
    m_origin += point;
}

void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::red);
    painter.drawEllipse(QPoint(60,60),50,50);
}
