#ifndef ENEMYPLANE2_H
#define ENEMYPLANE2_H
#include<QPixmap>
#include<bullet.h>
class enemyplane2
{
public:
    enemyplane2();
    void updatePosition();
    void shoot();
public:
    //敌机资源对象
    QPixmap m_enemy2;

    //敌机位置
    double m_X;
    double m_Y;

    //敌机的矩形边框，用于子弹的碰撞检测，测试敌机是否消失
    QRect m_Rect;

    //敌机状态，一定数量敌机不断循环，类似子弹机制
    bool m_Free;

    //敌机速度设置
    double m_Speed;

    //敌机2子弹弹匣
    bullet m_bullets[BULLET_NUM];

    //子弹发射间隔记录
    double m_recorder;
};

#endif // ENEMYPLANE2_H
