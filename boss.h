#ifndef BOSS_H
#define BOSS_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "config.h"

class boss
{
public:
    boss();

public:
    //发射子弹
    void shoot();

    //设置boss位置
    void setPosition(int x);


public:
    QPixmap m_boss;  //定义boss资源对象

    QPixmap m_blood1; //定义boss血量图片
    QPixmap m_blood2;
    QPixmap m_blood3;
    QPixmap m_blood4;
    QPixmap m_blood5;
    QPixmap m_blood6;
    QPixmap m_blood7;

    //boss坐标
    double m_X;
    double m_Y;

    //boss矩形边框，用于检测boss周边物体，当有飞机子弹碰撞到该边框时，则导致飞机扣血
    QRect m_Rect;

    //boss子弹弹匣，左右两侧都发射
    bullet m_bullets1[BULLET_NUM];
    bullet m_bullets2[BULLET_NUM];

    //子弹发射间隔记录
    double m_recorder;

    //设置飞机血量
    double m_health;

};

#endif // BOSS_H
