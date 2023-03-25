#ifndef START_H
#define START_H
#include <QWidget>
#include "mainscence.h"

#include <QPixmap>
#include <QPainter>
#include<set.h>
#include<music.h>
#include<help.h>
namespace Ui {
class start;
}

class Start : public QWidget
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);

    ~Start();
public:
    MainScence *w = new MainScence;

    help *h = new help;

    set *s = new set;


    //MainScence2 *w2 = new MainScence2;

    //MainScence3 *w3= new MainScence3;

    //背景图设置
    QPixmap m_background;

    //开始按钮绘制
    QPixmap m_startbutton;

    //退出按钮绘制
    QPixmap m_quitbutton;

    //帮助按钮绘制
    QPixmap m_helpbutton;

    //设置按钮绘制
    QPixmap m_setbutton;

    //英雄榜按钮绘制
    QPixmap m_herobutton;




    //绘制到屏幕中
    void paintEvent(QPaintEvent *event);

    //初始化场景
    void initScence();

    music w_gamesound;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();
public slots:
    void backHelpSlots();   //帮助界面返回槽
    void backSetSlots();    //设置界面转到槽
    void bgmOnSlots();  //bgm开槽
    void bgmOffSlots(); //bgm关槽
    void effectOnSlots();  //effect开槽
    void effectOffSlots();  //effect关槽
    void backMainscenceSlot();
    //void toTwoLevel();  //去往第二关
    void homeTwoSlot();  //关卡二回主界面槽
    void homeThreeSlot(); //关卡三回主界面槽

private:
    Ui::start *ui;
};

#endif // START_H

