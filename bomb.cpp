#include "bomb.h"

bomb::bomb()
{
    //将所有爆炸的图片放到数组中
    for(int i = 1 ; i <= BOMB_MAX ;i++)
    {
        //路径中存在%1占位，所以将字符串中的位子用i来代替
        QString str = QString (BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }
    //坐标
    m_X = 0;
    m_Y = 0;
    //爆炸状态
    m_Free = true;
    //当前播放图片下标
    m_index = 0;

    //播放爆炸间隔记录
    m_Recoder = 0;
}

void bomb::updateInfo()
{
    //空闲状态下的 爆炸效果 直接return 不需要爆炸
    if(m_Free)
    {
        return;
    }
    m_Recoder ++ ;
    //如果记录爆炸的实际间隔未达到爆炸间隔，则不需要切图，直接return
    if(m_Recoder < BOMB_INTERVAL)
    {
        return ;
    }
    //需要爆炸则需要重置间隔
    m_Recoder = 0;
    //切换到爆炸播放的图片的下标
    m_index ++;
    if(m_index >BOMB_MAX - 1)  //数组下标从零开始，最后一张图片下标为6
    {
        //计算下标大于6，重置为0，将爆炸效果重置为空闲
        m_index = 0;
        m_Free = true;
    }
}
