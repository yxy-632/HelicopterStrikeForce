#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include "heroplane.h"
#include "bullet.h"
#include "config.h"
#include <QTimer>
#include <QPixmap>
#include <QPainter>
namespace Ui {
class help;
}

class help : public QWidget
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

public:


    //定时器
       QTimer *m_Timer = new QTimer;

    //飞机对象
    HeroPlane m_hero;

    //背景图设置
    QPixmap m_background;

    //返回按钮设置
    QPixmap m_backbutton;

    //开始绘制帮助界面
    void setHelp();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *event);

    //初始化场景
    void initScence();

    //更新所有游戏中元素的坐标
    void updatePosition();


    //重写键盘移动事件
    void keyPressEvent(QKeyEvent *event);
signals:
    void backHelpsignal();  //帮助界面返回主界面信号
private slots:
    void on_pushButton_clicked();
    void updateThis();
private:
    Ui::help *ui;
};

#endif // HELP_H

