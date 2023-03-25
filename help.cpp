#include "help.h"
#include "ui_help.h"

#include "heroplane.h"
#include "bullet.h"
#include "config.h"
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include "QKeyEvent"
#include <QBitmap>
help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);

    //载入背景地图
    m_background.load(HELP_BACKGOURND);

    //载入返回按钮地图
    m_backbutton.load(BACK_BUTTON);
    ui->pushButton->setText("");
    ui->pushButton->move(GAME_WIDTH-235,-170);
    ui->pushButton->setIcon(m_backbutton);
    ui->pushButton->resize(m_backbutton.size());
    ui->pushButton->setMask(m_backbutton.mask());
    ui->pushButton->setIconSize(m_backbutton.size());

    //载入飞机地图
    m_hero.m_Plane.load(HELP_HREO);

    //设置飞机初始位置
    //m_hero.m_X = GAME_WIDTH * 0.5 +60;
   // m_hero.m_Y = GAME_HEIGHT * 0.5 +65;

    //单独界面测试
    //initScence();
    //setHelp();
}

help::~help()
{
    delete ui;
}

void help::setHelp()
{
    //启动定时器
    m_Timer->start();

    //监听定时器发送的信号
    //connect(&m_Timer, &QTimer::timeout , [=](){
        //更新游戏中元素的坐标
       // updatePosition();
        //绘制到屏幕中,手动调用绘制函数，重新调用窗口中的信息
        //update();
    //});
    connect(m_Timer, SIGNAL(timeout()),this,SLOT(updateThis()));
}

void help::paintEvent(QPaintEvent *event)
{
    //在当前坐标中重新画画
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,0,m_background);

    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

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

}

void help::initScence()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器设置
    m_Timer->setInterval(GAME_RATE);

    //设置飞机初始位置
    m_hero.m_X = GAME_WIDTH * 0.5 +60;
    m_hero.m_Y = GAME_HEIGHT * 0.5 +65;


}

void help::updatePosition()
{
    //计算所有非空闲子弹的当前坐标
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
}

void help::keyPressEvent(QKeyEvent *event)
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
    else if(event->key() == Qt::Key_J)
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

void help::on_pushButton_clicked()
{
    emit backHelpsignal();  //发送返回信号
}

void help::updateThis()
{
    //更新游戏中元素的坐标
        updatePosition();
        //绘制到屏幕中,手动调用绘制函数，重新调用窗口中的信息
        update();
}
