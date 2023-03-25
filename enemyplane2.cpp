#include "enemyplane2.h"

enemyplane2::enemyplane2()
{
    //敌机2资源加载
    m_enemy2.load(ENEMY2_PATH);

    //敌机的位置
    m_X = 0;
    m_Y = 0;

    //敌机的状态
    m_Free = true;

    //敌机速度
    m_Speed = ENEMY2_SPEED;

     //敌机矩形框，用于碰撞检测
    m_Rect.setWidth(m_enemy2.width());
    m_Rect.setWidth(m_enemy2.height());
    m_Rect.moveTo(m_X,m_Y);
}

void enemyplane2::updatePosition()
{
    //空闲状态敌机，不计算坐标
    if(m_Free)
    {
        return;
    }
    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //如果超出屏幕，重置空闲状态
    if(m_Y >= GAME_HEIGHT + m_Rect.height())
    {
        m_Free = true;
    }
}

void enemyplane2::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //如果记录的数字，未达到发射子弹时间间隔，直接return，不发射子弹
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }

    //达到发射时间
    m_recorder = 0;

    //发射子弹，遍历数组找到一个空闲的子弹进行发射
    for(int i = 0;i < BULLET_NUM; i++)
    {
        //若子弹空闲则进行发射
        if(m_bullets[i].m_Free)
        {
            //将空闲状态改为假
            m_bullets[i].m_Free = false;
            //设置子弹坐标
            m_bullets[i].m_X = m_X+m_Rect.width()*0.5+6 ;
            m_bullets[i].m_Y = m_Y +44 ;
            break;
        }
    }
}
