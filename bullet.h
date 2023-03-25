#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include <QRect>
#include "config.h"
class bullet
{
public:
    bullet();

    //更新子弹坐标
    void updatePosition();
    void updatePosition2();  //更新敌机子弹坐标
    void updatePositionBoss();  //更新boss子弹
public:
    //子弹资源对象
    QPixmap m_Bullet;
    QPixmap m_enemyBullet;
    QPixmap m_bossBullet;
    //子弹坐标
    double m_X;
    double m_Y;

    //子弹的移动速度
    double m_speed;

    double m_bossSpeed;
    //子弹是否闲置,当子弹出现在屏幕区域内时，则子弹为f，若非则相反。
    //若飞出屏幕则自动变为t，创建一个数组，类似于子弹拥有一个弹夹，省去了不断生成的过程。
    bool m_Free;

    //子弹的矩形边框，用于检测子弹碰撞，是否攻击到飞机
    QRect m_Rect;
};

#endif // BULLET_H
