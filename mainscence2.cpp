#include "mainscence2.h"
#include "ui_mainscence2.h"
#include "ui_mainscence3.h"
#include "config.h"
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <ctime>
#include <QSound>
#include "start.h"
#include <QBitmap>
#include <QPixmap>
#include <QDebug>
MainScence2::MainScence2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScence2)
{
    ui->setupUi(this);

    //载入第二关地图
    m_map.m_map1.load(MAP_PATH2);
    m_map.m_map2.load(MAP_PATH2);

    //载入游戏界面开始按钮
    m_start.load(GAME_START);
    ui->pushButton->setIcon(m_start);
    ui->pushButton->setText("");
    ui->pushButton->move(GAME_WIDTH-80,-20);
    ui->pushButton->resize(m_start.size());
    ui->pushButton->setMask(m_start.mask());
    ui->pushButton->setIconSize(m_start.size());

   //载入游戏界面暂停按钮
    m_quit.load(GAME_QUIT);
    ui->pushButton_2->setIcon(m_quit);
    ui->pushButton_2->setText("");
    ui->pushButton_2->move(GAME_WIDTH-80,-10);
    ui->pushButton_2->resize(m_quit.size());
    ui->pushButton_2->setMask(m_quit.mask());
    ui->pushButton_2->setIconSize(m_quit.size());

    //载入游戏界面设置按钮
    m_set.load(GAME_SET);
    ui->pushButton_3->setIcon(m_set);
    ui->pushButton_3->setText("");
    ui->pushButton_3->move(GAME_WIDTH-80,30);
    ui->pushButton_3->resize(m_set.size());
    ui->pushButton_3->setMask(m_set.mask());
    ui->pushButton_3->setIconSize(m_set.size());
    ui->pushButton_3->hide();

    //载入游戏界面帮助按钮
    m_help.load(GAME_HELP);
    ui->pushButton_4->setIcon(m_help);
    ui->pushButton_4->setText("");
    ui->pushButton_4->move(GAME_WIDTH-80,75);
    ui->pushButton_4->resize(m_help.size());
    ui->pushButton_4->setMask(m_help.mask());
    ui->pushButton_4->setIconSize(m_help.size());
    ui->pushButton_4->hide();

    //载入游戏图标
    m_back.load(SET_BACK);
    ui->pushButton_5->setIcon(m_back);
    ui->pushButton_5->setText("");
    ui->pushButton_5->move(-165,-60);
    ui->pushButton_5->resize(m_back.size());
    ui->pushButton_5->setMask(m_back.mask());
    ui->pushButton_5->setIconSize(m_back.size());

    //初始化关卡提示相关数据
    m_leveltips = true;
    m_level.load(GAME_LEVELTIPS2);
    m_leveltime = 0;
    m_condition=0;  //初始化第二关过关
    //调用初始化场景接口
    //initScence();

    //启动定时器
   // playGame();
    //加入失败图片
    m_loseflag.load(GAME_LOSEFLAG);

    //失败显示
    m_loseshow = false;

    connect(this,SIGNAL(toThreeLevelSignal()),this,SLOT(toThreeLevelSlot()));
}
void MainScence2::initScence()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器设置
    m_Timer->setInterval(GAME_RATE);

    //敌机出场时间间隔初始化
    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));

}

void MainScence2::playGame()
{
    //启动背景音乐
    //QSound::play(SOUND_BACKGROUND);
    //m_gamesound.m_bgm->play();

    //启动定时器
    m_Timer->start();

    //监听定时器发送的信号
    /*connect(&m_Timer, &QTimer::timeout , [=](){
        //敌机出场
        enemyToScence();
        //更新游戏中元素的坐标
        updatePosition();
        //绘制到屏幕中,手动调用绘制函数，重新调用窗口中的信息
        update();
        //碰撞检测
        collisionDetection();
    });*/
    connect(m_Timer, SIGNAL(timeout()),this,SLOT(updateMainscence()));

}

void MainScence2::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    if(m_hero.m_state == true)
    {
        //发射大招
        m_hero.skillshoot();
        //计算所有非空闲大招的当前坐标
        for(int i = 0;i < BULLET_NUM; i++)
        {
            //如果非空闲，则计算发射位置
            if(m_hero.m_skill[i].m_free == false)
            {
                m_hero.m_skill[i].updatePosition();
            }
        }
    }
    else
    {
        //发射子弹
        m_hero.shoot();
        //计算所有非空闲子弹的当前坐标
        for(int i = 0;i < BULLET_NUM; i++)
        {
            //如果非空闲，则计算发射位置
            if(m_hero.m_bullets[i].m_Free == false)
            {
                m_hero.m_bullets[i].updatePosition();
            }
        }
    }


    //敌机出场
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            m_enemys[i].updatePosition();
        }
    }

    //敌机二出场
    for(int i = 0; i < ENEMY2_NUM; i++)
    {
        if(m_enemys2[i].m_Free == false)
        {
            m_enemys2[i].updatePosition();
            m_enemys2[i].shoot();   //敌机二射击
            for(int j = 0;j < BULLET_NUM; j++)
            {
                //如果非空闲，则计算发射位置
                if(m_enemys2[i].m_bullets[j].m_Free == false)
                {
                    m_enemys2[i].m_bullets[j].updatePosition2();
                }
            }
        }
    }
    //敌机二子弹更新
    for(int i = 0; i < ENEMY2_NUM ; i ++)
    {
        for(int j = 0;j < BULLET_NUM; j++)
        {
            if(m_enemys2[i].m_Free == false)   //考虑相对速度
            {
                //如果非空闲，则计算发射位置
                if(m_enemys2[i].m_bullets[j].m_Free == false)
                {
                    m_enemys2[i].m_bullets[j].updatePosition2();
                }
            }
            else
            {
                //如果非空闲，则计算发射位置
                if(m_enemys2[i].m_bullets[j].m_Free == false)
                {
                    m_enemys2[i].m_bullets[j].m_Y += ENEMY2_SPEED;
                    m_enemys2[i].m_bullets[j].updatePosition2();
                }
            }

        }
    }

    //计算爆炸的图片
    for(int i = 0; i<BOMB_NUM; i++)
    {
        if(m_bombs[i].m_Free == false)
        {
            m_bombs[i].updateInfo();
        }
    }

    //血包更新************************************
    for(int i = 0; i < PROP_BLOODNUM; i++)
    {
        if(m_propbloods[i].m_free == false)
        {
            m_propbloods[i].updatePosition();
        }
    }

    //测试子弹
    //tmpbullet.m_Free = false;
    //tmpbullet.updatePosition();
}

void MainScence2::paintEvent(QPaintEvent *event)
{
    //在当前坐标中重新画画
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

    //绘制关卡提示
    if(m_leveltips == true)
    {
        painter.drawPixmap(100,GAME_HEIGHT * 0.5 ,m_level);
        m_leveltime ++;
        if(m_leveltime > GAME_LEVELTIME)
        {
            m_leveltips = false;
        }
    }


    //子弹选择
    if(m_hero.m_state == true)
    {
        if(m_hero.m_recoder < SKILL_INTERVAL)
        {
            //绘制大招子弹
            for(int i = 0;i < BULLET_NUM; i++)
            {
                //如果非空闲，则开始绘制子弹
                if(m_hero.m_skill[i].m_free == false)
                {
                    painter.drawPixmap(m_hero.m_skill[i].m_X ,m_hero.m_skill[i].m_Y ,m_hero.m_skill[i].m_skill);
                }

            }
            m_hero.m_recoder += 1;
        }
        else
        {
            m_hero.m_recoder = 0;
            m_hero.m_state = false;
        }
    }
    else
    {
        //绘制子弹
        for(int i = 0;i < BULLET_NUM; i++)
        {
            //如果非空闲，则开始绘制子弹
            if(m_hero.m_bullets[i].m_Free == false)
            {
                painter.drawPixmap(m_hero.m_bullets[i].m_X ,m_hero.m_bullets[i].m_Y ,m_hero.m_bullets[i].m_Bullet);
            }

        }
    }
    //绘制敌机
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }
    //绘制敌机二子弹
    for(int i = 0; i < ENEMY2_NUM; i++)
    {
        for(int j = 0;j < BULLET_NUM; j++)
        {
            //如果非空闲，则开始绘制子弹
            if(m_enemys2[i].m_bullets[j].m_Free == false)
            {
                painter.drawPixmap(m_enemys2[i].m_bullets[j].m_X ,m_enemys2[i].m_bullets[j].m_Y ,m_enemys2[i].m_bullets[j].m_enemyBullet);
            }
        }
    }
    //绘制敌机二
    for(int i = 0; i < ENEMY2_NUM; i++)
    {
        if(m_enemys2[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys2[i].m_X,m_enemys2[i].m_Y,m_enemys2[i].m_enemy2);
        }
    }

    //绘制爆炸
    for(int i = 0; i<BOMB_NUM; i++)
    {
        if(m_bombs[i].m_Free == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
    //测试子弹
    //painter.drawPixmap(tmpbullet.m_X,tmpbullet.m_Y,tmpbullet.m_Bullet);

    //绘制血包*********************************
    for(int i=0; i<PROP_BLOODNUM;i++)
    {
        if(m_propbloods[i].m_free==false)
        {
            painter.drawPixmap(m_propbloods[i].m_X,m_propbloods[i].m_Y,m_propbloods[i].m_propblood);
        }
    }

    //绘制血量
    if(m_hero.m_health >= 4)
    {
        painter.drawPixmap(0,0,m_hero.m_blood5);
    }
    else if(m_hero.m_health >= 3 && m_hero.m_health < 4)
    {
        painter.drawPixmap(0,0,m_hero.m_blood4);
    }
    else if(m_hero.m_health >= 2 && m_hero.m_health < 3)
    {
        painter.drawPixmap(0,0,m_hero.m_blood3);
    }
    else if(m_hero.m_health >= 1 && m_hero.m_health < 2)
    {
        painter.drawPixmap(0,0,m_hero.m_blood2);
    }
    else if(m_hero.m_health >= 0 && m_hero.m_health < 1)
    {
        painter.drawPixmap(0,0,m_hero.m_blood1);
    }
    else          //绘制失败界面
    {
        ;
    }
    // 绘制能量
    if(m_hero.m_energy >= 0 && m_hero.m_energy<1 )
     {
         painter.drawPixmap(0,50,m_hero.m_energy1);
     }
     else if(m_hero.m_energy>=1 && m_hero.m_energy<2 )
     {
         painter.drawPixmap(0,50,m_hero.m_energy2);
     }
     else if(m_hero.m_energy>=2 && m_hero.m_energy<3 )
     {
        painter.drawPixmap(0,50,m_hero.m_energy3);
     }
     else if(m_hero.m_energy>=3 && m_hero.m_energy<4 )
     {
        painter.drawPixmap(0,50,m_hero.m_energy4);
     }
     else if(m_hero.m_energy==4)
     {
        painter.drawPixmap(0,50,m_hero.m_energy5);
     }
    if(m_loseshow == true)
         {
             painter.drawPixmap(135,200,m_loseflag);
             m_loseshow = false;
             m_Timer->stop();
             ui->pushButton->hide();
             ui->pushButton_2->hide();
         }

}

void MainScence2::keyPressEvent(QKeyEvent *event)
{
    double x ;
    double y ;
    if(event->key() == Qt::Key_A)   //通过“w”，“a”，“s”，“d”来设置飞机移动方向
    {
        x = m_hero.m_X -m_hero.m_Rect.width() * 0.3;
        y = m_hero.m_Y;
    }
    else if (event->key() == Qt::Key_W)
    {
        x = m_hero.m_X;
        y = m_hero.m_Y - m_hero.m_Rect.height() *0.3;
    }
    else if (event->key() == Qt::Key_S)
    {
        x = m_hero.m_X;
        y = m_hero.m_Y + m_hero.m_Rect.height() *0.3;
    }
    else if (event->key() == Qt::Key_D)
    {
        x = m_hero.m_X + m_hero.m_Rect.width() * 0.3;
        y = m_hero.m_Y;
    }
    else if(event->key() == Qt::Key_P)
    {
        m_Timer->stop();
        return ;
    }
    else if(event->key() == Qt::Key_M)
    {
        m_Timer->start();
        return ;
    }
    else if(event->key() == Qt::Key_Y)
    {
        m_gamesound.m_bgm->stop();
        return ;
    }
    else if(event->key() == Qt::Key_U)
    {
        m_gamesound.m_bgm->play();
        return ;
    }
    else if(event->key() == Qt::Key_I)
    {
        m_gamesound.m_effect->setVolume(0);
        return ;
    }
    else if(event->key() == Qt::Key_O)
    {
        m_gamesound.m_effect->setVolume(SOUND_VOLUME);
        return ;
    }
    else if(event->key() == Qt::Key_J && m_hero.m_energy == 4)  //设置大招键位
    {
        m_hero.updateSkill();
        return ;
    }
    else
    {
        return;
    }
    if(x <= 0 )   //判断飞机是否飞出边框
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HEIGHT - m_hero.m_Rect.height();
    }

    m_hero.setPosition(x,y);
}

void MainScence2::enemyToScence()
{
    //未达到出场的间隔
    m_recorder ++;
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }
    //到达出场间隔
    m_recorder = 0;
    for(int i=0 ; i < ENEMY_NUM ; i++)
    {
        //如果敌机是空闲的，则可以出场
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free = false;
            //出场坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = - m_enemys[i].m_Rect.height();
            break;
        }
        if(m_enemys2[i].m_Free)   //敌机二随即出场
        {
            m_enemys2[i].m_Free = false;
            //出场坐标
            m_enemys2[i].m_X = rand()%(GAME_WIDTH - m_enemys2[i].m_Rect.width());
            m_enemys2[i].m_Y = - m_enemys2[i].m_Rect.height();
            break;
        }
    }
}

void MainScence2::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0;i < ENEMY_NUM; i++)
    {
        //若是空闲的飞机则执行下一次循环
        //空闲的飞机的顺序不一定是按照顺序而来的，可能会中间隔断，所以直到找到空闲的飞机，否则就直接跳过
        if(m_enemys[i].m_Free)
        {
            continue;
        }
        //遍历所有非空闲子弹
        //空闲子弹执行下一次的循环，与飞机原理相似

        /*if(m_hero.m_bullets[j].m_Free && m_hero.m_skill[j].m_free)
        {
            continue;
        }*/
        //如果子弹和飞机相交，发生碰撞，同时将飞机和子弹空闲状态设置为真
        //判断该状态下是大招状态还是子弹状态
        if(m_hero.m_state == true)
        {
            //空闲大招执行下一次的循环，与飞机原理相似
            for(int j = 0; j < BULLET_NUM; j++)
            {
                if(m_hero.m_skill[j].m_free)
                {
                    continue;
                }
                if(m_enemys[i].m_Rect.intersects(m_hero.m_skill[j].m_rect))
                {
                    m_enemys[i].m_Free = true;
                    m_hero.m_skill[j].m_free = true;

                    //播放爆炸效果
                    for(int k = 0; k<BOMB_NUM;k++)
                    {
                        if(m_bombs[k].m_Free)
                        {
                            //播放爆炸音效
                            //QSound::play(SOUND_BOMB);
                            m_gamesound.m_effect->play();

                            //空闲状态可以爆炸
                            m_bombs[k].m_Free = false;
                            //更新爆炸坐标
                            m_bombs[k].m_X=m_enemys[i].m_X;
                            m_bombs[k].m_Y=m_enemys[i].m_Y;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            int randtmp=rand()%100;   //****************血包概率控制
            for(int j = 0; j < BULLET_NUM; j++)
            //空闲子弹执行下一次的循环，与飞机原理相似
            {
                if(m_hero.m_bullets[j].m_Free )
                {
                    continue;
                }

                if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
                {
                    m_enemys[i].m_Free = true;
                    m_hero.m_bullets[j].m_Free = true;
                    //血包出现
                    for(int k=0;k<PROP_BLOODNUM;k++)
                    {
                        //int qqq=rand()%100;
                        if(m_propbloods[k].m_free==false)
                        {
                            continue;
                        }
                        if(randtmp<30)
                        {
                            m_propbloods[k].m_free=false;
                            m_propbloods[k].m_X=m_enemys[i].m_X;
                            m_propbloods[k].m_Y=m_enemys[i].m_Y;
                            break;
                        }
                    }

                    //播放爆炸效果
                    for(int k = 0; k<BOMB_NUM;k++)
                    {
                        if(m_bombs[k].m_Free)
                        {
                            //播放爆炸音效
                            //QSound::play(SOUND_BOMB);
                            m_gamesound.m_effect->play();

                            //空闲状态可以爆炸
                            m_bombs[k].m_Free = false;
                            //更新爆炸坐标
                            m_bombs[k].m_X=m_enemys[i].m_X;
                            m_bombs[k].m_Y=m_enemys[i].m_Y;
                            break;
                        }
                    }
                    if(m_hero.m_energy!=HERO_ENERGY )    //能量槽不满则加
                    {
                        m_hero.m_energy+=UP_ENERGY;
                    }
                    else                //满则重置
                    {
                        ;
                    }

                }
            }
        }
        //敌机与飞机碰撞检测
        if(m_enemys[i].m_Rect.intersects(m_hero.m_Rect))
        {
            m_enemys[i].m_Free = true;
            for(int k = 0; k<BOMB_NUM;k++)
            {
                if(m_bombs[k].m_Free)
                {
                    //播放爆炸音效
                    //QSound::play(SOUND_BOMB);
                    m_gamesound.m_effect->play();

                    //空闲状态可以爆炸
                    m_bombs[k].m_Free = false;
                    //更新爆炸坐标
                    m_bombs[k].m_X=m_enemys[i].m_X;
                    m_bombs[k].m_Y=m_enemys[i].m_Y;
                    break;
                }
            }
            m_hero.m_health -= LOSE_BLOOD;
            if(m_hero.m_health <0)
            {
                //m_Timer->stop();
                m_loseshow=true;
            }
        }
    }
}

void MainScence2::collisionDetection2()
{
    //遍历所有非空闲的敌机2
    for(int i = 0;i < ENEMY_NUM; i++)
    {
        //若是空闲的飞机则执行下一次循环
        //空闲的飞机的顺序不一定是按照顺序而来的，可能会中间隔断，所以直到找到空闲的飞机，否则就直接跳过
        if(m_enemys2[i].m_Free)
        {
            continue;
        }
        //遍历所有非空闲子弹
        //空闲子弹执行下一次的循环，与飞机原理相似

        /*if(m_hero.m_bullets[j].m_Free && m_hero.m_skill[j].m_free)
        {
            continue;
        }*/
        //如果子弹和飞机相交，发生碰撞，同时将飞机和子弹空闲状态设置为真
        //判断该状态下是大招状态还是子弹状态
        if(m_hero.m_state == true)
        {
            //空闲大招执行下一次的循环，与飞机原理相似
            for(int j = 0; j < BULLET_NUM; j++)
            {
                if(m_hero.m_skill[j].m_free)
                {
                    continue;
                }
                if(m_enemys2[i].m_Rect.intersects(m_hero.m_skill[j].m_rect))
                {
                    m_enemys2[i].m_Free = true;
                    m_hero.m_skill[j].m_free = true;

                    //播放爆炸效果
                    for(int k = 0; k<BOMB_NUM;k++)
                    {
                        if(m_bombs[k].m_Free)
                        {
                            //播放爆炸音效
                            //QSound::play(SOUND_BOMB);
                            m_gamesound.m_effect->play();

                            //空闲状态可以爆炸
                            m_bombs[k].m_Free = false;
                            //更新爆炸坐标
                            m_bombs[k].m_X=m_enemys2[i].m_X;
                            m_bombs[k].m_Y=m_enemys2[i].m_Y;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            int randtmp=rand()%100;
            for(int j = 0; j < BULLET_NUM; j++)
            //空闲子弹执行下一次的循环，与飞机原理相似
            {
                if(m_hero.m_bullets[j].m_Free )
                {
                    continue;
                }
                if(m_enemys2[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
                {
                    m_enemys2[i].m_Free = true;
                    m_hero.m_bullets[j].m_Free = true;
                    for(int k=0;k<PROP_BLOODNUM;k++)
                    {
                        //int qqq=rand()%100;
                        if(m_propbloods[k].m_free==false)
                        {
                            continue;
                        }
                        if(randtmp<30)
                        {
                            m_propbloods[k].m_free=false;
                            m_propbloods[k].m_X=m_enemys2[i].m_X;
                            m_propbloods[k].m_Y=m_enemys2[i].m_Y;
                            break;
                        }
                    }

                    //播放爆炸效果
                    for(int k = 0; k<BOMB_NUM;k++)
                    {
                        if(m_bombs[k].m_Free)
                        {
                            //播放爆炸音效
                            //QSound::play(SOUND_BOMB);
                            m_gamesound.m_effect->play();

                            //空闲状态可以爆炸
                            m_bombs[k].m_Free = false;
                            //更新爆炸坐标
                            m_bombs[k].m_X=m_enemys2[i].m_X;
                            m_bombs[k].m_Y=m_enemys2[i].m_Y;
                            break;
                        }
                    }
                    if(m_hero.m_energy!=HERO_ENERGY )    //能量槽不满则加
                    {
                        m_hero.m_energy+=UP_ENERGY;
                    }
                    else                //满则重置
                    {
                        ;
                    }

                }
            }
        }
        //敌机2与飞机碰撞检测
        if(m_enemys2[i].m_Rect.intersects(m_hero.m_Rect))
        {
            m_enemys2[i].m_Free = true;
            for(int k = 0; k<BOMB_NUM;k++)
            {
                if(m_bombs[k].m_Free)
                {
                    //播放爆炸音效
                    //QSound::play(SOUND_BOMB);
                    m_gamesound.m_effect->play();

                    //空闲状态可以爆炸
                    m_bombs[k].m_Free = false;
                    //更新爆炸坐标
                    m_bombs[k].m_X=m_enemys2[i].m_X;
                    m_bombs[k].m_Y=m_enemys2[i].m_Y;
                    break;
                }
            }
            m_hero.m_health -= LOSE_BLOOD;
            if(m_hero.m_health <0)
            {
                //m_Timer->stop();
                m_loseshow=true;
            }
        }
        //敌机2子弹与飞机碰撞检测
        for(int j = 0; j < BULLET_NUM; j++)
        {
            //空闲子弹执行下一次的循环，与飞机原理相似
            if(m_enemys2[i].m_bullets[j].m_Free )
            {
                continue;
            }
            if(m_enemys2[i].m_bullets[j].m_Rect.intersects(m_hero.m_Rect))
            {
                m_enemys2[i].m_bullets[j].m_Free = true;
                m_hero.m_health -= (LOSE_BLOOD * 0.2);
                if(m_hero.m_health <0)
                {
                    //m_Timer->stop();
                    m_loseshow=true;
                }
            }
        }

    }
    //遍历所有非空闲的血包
}

void MainScence2::collisionDetection3()    //血包碰撞检测
{
    for(int i=0;i<PROP_BLOODNUM;i++)
    {
        if(m_propbloods[i].m_free)
        {
            continue;
        }
        if(m_propbloods[i].m_rect.intersects(m_hero.m_Rect))
        {
           // m_propbloods[i].m_propblood.load(PROP_PICK);
            m_propbloods[i].m_free=true;
            if(m_hero.m_health<=3)
            {
                m_hero.m_health += PROP_BLOODUP;
                break;
            }
            else
            {
                m_hero.m_health -= 2;
            }
        }
    }
}

void MainScence2::conditionCheck()
{
    if(m_condition < TWO_CONDITION)
    {
        m_condition+=0.1;
    }
    else
    {
        m_condition=0;
        //发送去第三关的信号
        emit toThreeLevelSignal();
    }
}

void MainScence2::updateMainscence()
{
    //敌机出场
    enemyToScence();
    //更新游戏中元素的坐标

    //绘制到屏幕中,手动调用绘制函数，重新调用窗口中的信息
     updatePosition();


    update();

    //碰撞检测
    collisionDetection();
    collisionDetection2();
    collisionDetection3();

    //过关检测
    conditionCheck();
}

void MainScence2::toThreeLevelSlot()
{
    this->m_Timer->stop();
     disconnect(this->m_Timer, SIGNAL(timeout()),this,SLOT(updateMainscence()));  //断开连接
     this->hide();          //第二关窗口隐藏
     w3->m_hero.m_health=this->m_hero.m_health;      //继承上一关的血量
     w3->m_hero.m_energy=this->m_hero.m_energy;  //继承上一关的能量
     //第三关数据清零
         //敌机归零
         for(int i = 0; i < ENEMY_NUM; i ++)
         {
             w3->m_enemys[i].m_Free = true;
         }
         //敌机2归零
         for(int i =  0; i < ENEMY2_NUM ; i ++)
         {
             w3->m_enemys2[i].m_Free = true;
             for(int j = 0; j < BULLET_NUM ; j ++)
             {
                 w3->m_enemys2[i].m_bullets[j].m_Free = true;
             }
         }
         //英雄子弹清零
         for(int i = 0; i < BULLET_NUM ; i ++)
         {
             w3->m_hero.m_bullets[i].m_Free = true;
         }
         //英雄技能清零
         for(int i = 0; i < BULLET_NUM ; i ++)
         {
             w3->m_hero.m_skill[i].m_free = false ;
         }
         //爆炸效果清零
         for(int i = 0; i < BOMB_NUM ; i++)
         {
             w3->m_bombs[i].m_Free = true ;
         }
         //血包清零
         for(int i = 0; i < PROP_BLOODNUM ; i++)
         {
             w3->m_propbloods[i].m_free = true;
         }
         //boss子弹清零
         for(int i = 0; i < BULLET_NUM ; i++)
         {
             w3->m_boss.m_bullets1[i].m_Free = true;
             w3->m_boss.m_bullets2[i].m_Free = true;
         }
         w3->m_boss.m_health = BOSS_HEALTH;
         w3->m_leveltime = 0;
         w3->ui->pushButton_2->show();
         w3->ui->pushButton->show();
         w3->m_leveltips = true;
         w3->m_winshow=false;
         w3->ui->pushButton_6->hide();
     w3->m_hero.m_X = (GAME_WIDTH - m_hero.m_Plane.width()) * 0.5;
     w3->m_hero.m_Y = GAME_HEIGHT - m_hero.m_Plane.height();
     w3->move(this->x(),this->y());
     w3->initScence();   //初始化第二关
     w3->playGame();   //开始
     w3->show();
}


void MainScence2::on_pushButton_clicked()
{
    m_Timer->start(); //开始游戏
    ui->pushButton->hide();
    ui->pushButton_2->show();
}

void MainScence2::on_pushButton_2_clicked()
{
    m_Timer->stop();//游戏暂停
    ui->pushButton_2->hide();
    ui->pushButton->show();
}
MainScence2::~MainScence2()
{
    delete ui;
}

void MainScence2::on_pushButton_5_clicked()
{
    m_Timer->stop();
    disconnect(m_Timer, SIGNAL(timeout()),this,SLOT(updateMainscence()));
    emit homeTwoSignal();
}
