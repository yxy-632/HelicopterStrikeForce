#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "config.h"
#include"skill.h"
class HeroPlane
{
public:
    HeroPlane();

    //发射子弹
    void shoot();

    //设置飞机位置
    void setPosition(int x,int y);

public:
    QPixmap m_Plane;  //定义飞机资源对象

    //飞机坐标
    double m_X;
    double m_Y;

    //飞机矩形边框，用于检测飞机周边物体，当有敌机或敌机子弹碰撞到该边框时，则导致飞机扣血
    QRect m_Rect;

    //飞机子弹弹匣
    bullet m_bullets[BULLET_NUM];

    //子弹发射间隔记录
    double m_recorder;

    //设置飞机血量
    double m_health;


    QPixmap m_blood1; //定义飞机血量图片
        QPixmap m_blood2;
        QPixmap m_blood3;
        QPixmap m_blood4;
        QPixmap m_blood5;
    QPixmap m_energy1; //定义飞机能量
            QPixmap m_energy2;
            QPixmap m_energy3;
            QPixmap m_energy4;
            QPixmap m_energy5;

     double m_energy;
     //设置飞机大招
        skill m_skill[BULLET_NUM];

         //设置大招发射间隔记录
         double m_skillrecorder;

         //大招状态
         bool m_state;

         //记录大招持续时长
         double m_recoder;

         //更新大招状态
         void updateSkill();


         //发射大招
         void skillshoot();
};

#endif // HEROPLANE_H
