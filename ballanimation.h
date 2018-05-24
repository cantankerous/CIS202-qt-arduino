
#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void addToOrigin(const QPoint &point);
    void wall_detect();


signals:

public slots:
    void paintEvent(QPaintEvent* event);
private:
    QPoint m_origin;
    QPoint m_test;
    int left_right=1;
    int up_down=1;
    int e_width = 10;
    int e_height = 10;
    int radius = e_height / 2;
};

#endif // BALLANIMATION_H
