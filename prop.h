#ifndef PROP_H
#define PROP_H
#include<QPixmap>
#include<QRect>
class prop
{
public:
    prop();
    void updatePosition(); //更新血包位置
public:
    QPixmap m_propblood;  //血包图片

    double m_X;
    double m_Y;

    QRect m_rect;  //血包边框

    bool m_free;  //血包是否空闲

    double m_Speed;  //血包移动速度

};

#endif // PROP_H
