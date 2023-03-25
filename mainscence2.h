#ifndef MAINSCENCE2_H
#define MAINSCENCE2_H
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
#include <enemyplane2.h>
#include <prop.h>
#include"mainscence3.h"
namespace Ui {
class MainScence2;
}

class MainScence2 : public QWidget
{
    Q_OBJECT

public:
    explicit MainScence2(QWidget *parent = nullptr);
    ~MainScence2();
    //初始化场景
    void initScence();

   MainScence3 *w3 = new MainScence3;
    //游戏界面开始、暂停设置、帮助图标
    QPixmap m_start, m_quit,m_set,m_help,m_back;

    //定时器
    QTimer *m_Timer = new QTimer;

    //地图对象
    map m_map;

    //飞机对象
    HeroPlane m_hero;

    //敌机出场数组
    enemyplane m_enemys[ENEMY_NUM];

    //敌机二
    enemyplane2 m_enemys2[ENEMY2_NUM];

    //血包数组
    prop m_propbloods[PROP_BLOODNUM];

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

    //碰撞检测函数
    void collisionDetection();

    void collisionDetection2();

    void collisionDetection3();

    //是否进行关卡提示
    bool m_leveltips ;

    //关卡图片
    QPixmap m_level;

    //关卡提示时间
    double m_leveltime;

    //过关时间
    double m_condition;

    //失败图片
    QPixmap m_loseflag;

    //失败图片显示；
    bool m_loseshow;
    //过关检测函数
    void conditionCheck();

public slots:
   void updateMainscence();  //游戏界面刷新
   void toThreeLevelSlot();  //转到第三关的槽
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();

signals:
    void toThreeLevelSignal();
    void homeTwoSignal();   //从关卡二返回主界面
public:
    Ui::MainScence2 *ui;
};

#endif // MAINSCENCE2_H
