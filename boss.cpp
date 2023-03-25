#include "boss.h"

boss::boss()
{
    //初始化加载boss图片资源
    m_boss.load(BOSS_PATH);

    //加载boss血量资源
    m_blood1.load(BOSS_BLOOD1);
    m_blood2.load(BOSS_BLOOD2);
    m_blood3.load(BOSS_BLOOD3);
    m_blood4.load(BOSS_BLOOD4);
    m_blood5.load(BOSS_BLOOD5);
    m_blood6.load(BOSS_BLOOD6);
    m_blood7.load(BOSS_BLOOD7);

    //初始化boss坐标
    m_X = 170;
    m_Y = GAME_HEIGHT * 0.5 - 200;

    //初始化矩形边框
    m_Rect.setWidth(m_boss.width());
    m_Rect.setHeight(m_boss.height());
    m_Rect.moveTo(m_X,m_Y);  //设置矩形边框初始位置

    //初始化血量
    m_health = BOSS_HEALTH;
}

void boss::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //如果记录的数字，未达到发射子弹时间间隔，直接return，不发射子弹
    if(m_recorder < BOSS_INTERVAL)
    {
        return;
    }

    //达到发射时间
    m_recorder = 0;

    //发射子弹，遍历数组找到一个空闲的子弹进行发射，发射两侧子弹
    for(int i = 0;i < BULLET_NUM; i++)
    {
        //若子弹空闲则进行发射
        if(m_bullets1[i].m_Free)
        {
            //将空闲状态改为假
            m_bullets1[i].m_Free = false;
            //设置子弹坐标
            m_bullets1[i].m_X = m_X+m_Rect.width()*0.5 - 28;
            m_bullets1[i].m_Y = m_Y + 110;
            break;
        }
    }
    //发射两侧子弹
    for(int i = 0;i < BULLET_NUM; i++)
    {
        if(m_bullets2[i].m_Free)
        {
            //将空闲状态改为假
            m_bullets2[i].m_Free = false;
            //设置子弹坐标
            m_bullets2[i].m_X = m_X+m_Rect.width()*0.5 + 8;
            m_bullets2[i].m_Y = m_Y + 110;
            break;
        }
    }
}

void boss::setPosition(int x)
{
    m_X = x;
    m_Rect.moveTo(m_X,m_Y);
}
