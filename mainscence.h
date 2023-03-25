#ifndef MAINSCENCE_H
#define MAINSCENCE_H
#include <QTimer>
#include <QWidget>
#include "map.h"
#include "heroplane.h"
#include <QKeyEvent>
#include "bullet.h"
#include "enemyplane.h"
#include "music.h"
#include "bomb.h"
#include "enemyplane2.h"
#include<mainscence2.h>
QT_BEGIN_NAMESPACE
namespace Ui { class mainscence; }
QT_END_NAMESPACE

class MainScence : public QWidget
{
    Q_OBJECT

public:
    MainScence(QWidget *parent = nullptr);
    ~MainScence();

    //初始化场景
    void initScence();

    //第二关对象
    MainScence2 *w2 =new MainScence2;
    //游戏界面开始、暂停设置、帮助图标
    QPixmap m_start, m_quit,m_set,m_help,m_back;

    //定时器
    QTimer *m_Timer= new QTimer;

    //地图对象
    map m_map;

    //飞机对象
    HeroPlane m_hero;

    //敌机出场数组
    enemyplane m_enemys[ENEMY_NUM];



    //敌机出场间隔记录
    double m_recorder;                      //*******************************新场景增添测试****************二场景还要有，一场景不能删除

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

    //是否进行关卡提示
       bool m_leveltips ;

       //关卡图片
       QPixmap m_level;

       //关卡提示时间
       double m_leveltime;

       //过第一关条件
       double m_condition;
       //过关检测
       void conditionCheck();
       //失败图片
       QPixmap m_loseflag;

       //失败图片显示；
       bool m_loseshow;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();

signals:
    void backMainscenceSignal();  //返回主界面
    void toTwoLevelSignal();
    void loseSignal();   //失败信号
public slots:
    void updateMainscence();
    void toTwoLevelSlot();
    void loseSlot();  //失败槽
public:
    Ui::mainscence *ui;
};
#endif // MAINSCENCE_H
