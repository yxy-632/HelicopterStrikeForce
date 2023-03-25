#include "prop.h"
#include"config.h"
prop::prop()
{
    m_propblood.load(PROP_BLOOD); //加载血包图片
    m_X=70;  //设置血包初始
    m_Y=0;
    m_rect.setWidth(m_propblood.width());   //设置矩形边框
    m_rect.setHeight(m_propblood.height());
    m_rect.moveTo(m_X,m_Y);
    m_Speed=PROP_BLOODSPEED;    //设置血包移动速度
    m_free=true;            //设置血包初始状态
}

void prop::updatePosition()
{
    if(m_free)
    {
        return;
    }
    m_Y+=m_Speed;
    m_rect.moveTo(m_X,m_Y);

    //如果超出屏幕，重置空闲状态
    if(m_Y >= GAME_HEIGHT + m_rect.height())
    {
        m_free = true;
    }
}
