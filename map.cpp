#include "map.h"
#include "config.h"
map::map()
{
    m_map1.load(MAP_PATH);  //初始化第一关地图
    m_map2.load(MAP_PATH);

    m_map1_posY = -GAME_HEIGHT;   //初始化地图坐标
    m_map2_posY = 0;

    m_scroll_speed = MAP_SCROLL_SPEED;  //地图滚动速度
}

void map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >=0)
    {
        m_map1_posY = -GAME_HEIGHT;
    }
    m_map2_posY += m_scroll_speed;
    if(m_map2_posY >= GAME_HEIGHT)
    {
        m_map2_posY = 0;
    }
}
