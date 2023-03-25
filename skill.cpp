#include "skill.h"
#include<config.h>
skill::skill()
{
    //初始化大招状态
        m_free = false;

        //初始化大招图片
        m_skill.load(SKILL_BULLET);

        //初始化矩形边框
        m_rect.setWidth(m_skill.width());
        m_rect.setHeight(m_skill.height());

        //初始化大招坐标
        m_X = GAME_WIDTH * 0.5 - m_skill.width() * 0.5;
        m_Y = GAME_HEIGHT;

        //大招速度
        m_speed = BULLET_SPEED;

}

void skill::updatePosition()
{
    //在不可用状态下的大招，不需要计算坐标
    if(m_free)
    {
        return;
    }
    //子弹向上移动
    m_Y -= m_speed;
    m_rect.moveTo(m_X,m_Y);

    if(m_Y <= - m_rect.height())  //若子弹超出窗口，则子弹重新变为空闲状态
    {
        m_free = true;
    }
}
