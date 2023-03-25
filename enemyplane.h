#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "config.h"
class enemyplane
{
public:
    enemyplane();

    //敌机更新坐标
    void updatePosition();
public:

    //敌机资源对象
    QPixmap m_enemy;

    //敌机位置
    double m_X;
    double m_Y;

    //敌机的矩形边框，用于子弹的碰撞检测，测试敌机是否消失
    QRect m_Rect;

    //敌机状态，一定数量敌机不断循环，类似子弹机制
    bool m_Free;

    //敌机速度设置
    double m_Speed;
};

#endif // ENEMYPLANE_H

