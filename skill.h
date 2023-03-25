#ifndef SKILL_H
#define SKILL_H
#include <QPixmap>
#include<QRect>
class skill
{
public:
    skill();
public:
    //大招子弹是否可用
        bool m_free;


        //大招所用子弹
        QPixmap m_skill;

        //大招子弹的矩形格
        QRect m_rect;

        //更新大招坐标
        void updatePosition();

        //大招坐标
        double m_X;
        double m_Y;

        //大招的移动速度
        double m_speed;


};

#endif // SKILL_H
