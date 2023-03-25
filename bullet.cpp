#include "bullet.h"
#include <QPixmap>
#include <QRect>
#include "config.h"
bullet::bullet()
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH);
    m_enemyBullet.load(ENEMY2_BULLETPATH);//加载enemy子弹
    m_bossBullet.load(BOSS_BULLET);  //加载boss子弹
    //子弹坐标
    m_X = GAME_WIDTH * 0.5 - m_Bullet.width() * 0.5;
    m_Y = GAME_HEIGHT;

    //子弹状态
    m_Free = true;

    //子弹速度
    m_speed = BULLET_SPEED;

    m_bossSpeed = BOSS_SPEED;
    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);

}

void bullet::updatePosition()
{
    //空闲状态下的子弹，即在弹匣内的子弹不需要计算坐标
    if(m_Free)
    {
        return;
    }
    //子弹向上移动
    m_Y -= m_speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y <= - m_Rect.height())  //若子弹超出窗口，则子弹重新变为空闲状态
    {
        m_Free = true;
    }
}

void bullet::updatePosition2()
{

    //空闲状态下的子弹，即在弹匣内的子弹不需要计算坐标
    if(m_Free)
    {
        return;
    }
    //子弹向下移动
    m_Y += m_speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y >= GAME_HEIGHT+ m_Rect.height())  //若子弹超出窗口，则子弹重新变为空闲状态
    {
        m_Free = true;
    }
}

void bullet::updatePositionBoss()
{
    //空闲状态下的子弹，即在弹匣内的子弹不需要计算坐标
    if(m_Free)
    {
        return;
    }
    //子弹向下移动
    m_Y += m_bossSpeed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y >= GAME_HEIGHT+ m_Rect.height())  //若子弹超出窗口，则子弹重新变为空闲状态
    {
        m_Free = true;
    }
}
