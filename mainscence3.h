#ifndef MAINSCENCE3_H
#define MAINSCENCE3_H
#include <QTimer>
#include <QWidget>
#include "map.h"
#include "heroplane.h"
#include <QKeyEvent>
#include <QPixmap>
#include "bullet.h"
#include "enemyplane.h"
#include "music.h"
#include "bomb.h"
#include <QWidget>
#include <QWidget>
#include "enemyplane2.h"
#include "boss.h"
#include "prop.h"
#include "bug.h"
namespace Ui {
class MainScence3;
}

class MainScence3 : public QWidget
{
    Q_OBJECT

public:
    explicit MainScence3(QWidget *parent = nullptr);
    ~MainScence3();
    //初始化场景
    void initScence();
    //游戏界面开始、暂停设置、帮助图标
    QPixmap m_start, m_quit,m_set,m_help,m_back;


    //定时器
    QTimer *m_Timer = new QTimer;

    //地图对象
    map m_map;

    //飞机对象
    HeroPlane m_hero;

    //boss对象
    boss m_boss;

    //敌机出场数组
    enemyplane m_enemys[ENEMY_NUM];

    //敌机出场数组
    enemyplane2 m_enemys2[ENEMY_NUM];

    //敌机出场间隔记录
    double m_recorder;

    //爆炸数组
    bomb m_bombs[BOMB_NUM];

    //背景音乐和音效
    music m_gamesound;

    //子弹对象
    //bullet tmpbullet;

    //启动游戏
    void playGame();

    //更新所有游戏中元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *event);

    //重写键盘移动事件
    void keyPressEvent(QKeyEvent *event);

    //敌机出场函数
    void enemyToScence();

    //boss出场及位置变换函数
    void bossToScence();

    //碰撞检测函数,检测敌机相关碰撞
    void collisionDetection();

    //检测函数检测敌机2相关碰撞
    void collisionDetection2();

    //检测英雄吃血包
    void collisionDetection3();
    //检测函数检测boss间相关碰撞
    void collisionDetection4();

    //是否进行关卡提示
    bool m_leveltips ;

    //血包数组
    prop m_propbloods[PROP_BLOODNUM];
    //关卡图片
    QPixmap m_level;

    //关卡提示时间
    double m_leveltime;

    //boss 位置刷新时间
    double bosstime;
    //失败图片
    QPixmap m_loseflag;

    QPixmap m_winflag;
    //失败图片显示；
    bool m_loseshow;
    bool m_winshow;

    bug *m_bug=new bug;
public slots:
   void updateMainscence();  //游戏界面刷新
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

signals:
    void homeThreeSignal();
public:
    Ui::MainScence3 *ui;
};

#endif // MAINSCENCE3_H
