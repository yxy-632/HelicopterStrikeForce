#ifndef MAP_H
#define MAP_H
#include <QPixmap>

class map
{
public:
    map();
    void mapPosition();  //地图滚动坐标设计
public:
   QPixmap m_map1;   //定义两个图片对象，让图片滚动起来
   QPixmap m_map2;

   double m_map1_posY;   //定义滚动时图片Y轴坐标位置，因为X轴不变故不设置X轴
   double m_map2_posY;

   double m_scroll_speed; //地图的滚动速度
};

#endif // MAP_H
