#include "heroplane.h"
#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"

HeroPlane::HeroPlane()
{
    //初始化加载飞机图片资源
    m_Plane.load(HERO_PATH);

    //初始化飞机坐标
    m_X = (GAME_WIDTH - m_Plane.width()) * 0.5;
    m_Y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);  //设置矩形边框初始位置

    //初始化血量
    m_health=HERO_HEALTH;

    //加载血量资源
        m_blood1.load(HERO_BLOOD1);
        m_blood2.load(HERO_BLOOD2);
        m_blood3.load(HERO_BLOOD3);
        m_blood4.load(HERO_BLOOD4);
        m_blood5.load(HERO_BLOOD5);
     //加载能量资源
        m_energy1.load(HERO_ENERGY1);
        m_energy2.load(HERO_ENERGY2);
        m_energy3.load(HERO_ENERGY3);
        m_energy4.load(HERO_ENERGY4);
        m_energy5.load(HERO_ENERGY5);

      //能量值
        m_energy=0;
        //大招状态
            m_state = false;

            //大招持续时长，初始化计时器
            m_recoder = 0;
}

void HeroPlane::shoot()
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
            m_bullets[i].m_X = m_X+m_Rect.width()*0.5 - 10;
            m_bullets[i].m_Y = m_Y - 25 ;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void HeroPlane::skillshoot()
{
    //累加时间间隔记录变量
    m_skillrecorder++;

    //如果记录的数字，未达到发射子弹时间间隔，直接return，不发射大招
    if(m_skillrecorder < BULLET_INTERVAL)
    {
        return;
    }

    //达到发射时间
    m_skillrecorder = 0;

    //发射子弹，遍历数组找到一个空闲的子弹进行发射
    for(int i = 0;i < BULLET_NUM; i++)
    {
        //若子弹空闲则进行发射
        if(m_skill[i].m_free)
        {
            //将空闲状态改为假
            m_skill[i].m_free = false;
            //设置子弹坐标
            m_skill[i].m_X = m_X+m_Rect.width()*0.5 - 60;
            m_skill[i].m_Y = m_Y - 60 ;
            break;
        }
    }
}
void HeroPlane::updateSkill()
{
    m_state = true;
    m_energy=0;
}
