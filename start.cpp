#include "start.h"
#include "ui_start.h"
#include "mainscence.h"
#include "config.h"
#include <QPixmap>
#include <QPainter>
#include <QBitmap>
#include<music.h>
#include<QTimer>
#include<set.h>
#include "ui_mainscence.h"
Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);

    //载入背景图
     m_background.load(START_BACKGOURND);

    //载入开始按钮图
    m_startbutton.load(START_BUTTON);
    ui->pushButton->setText("");
    ui->pushButton->move(GAME_WIDTH*0.5-80,GAME_HEIGHT*0.5-80);
    ui->pushButton->setIcon(m_startbutton);
    ui->pushButton->resize(m_startbutton.size());
    ui->pushButton->setMask(m_startbutton.mask());
    ui->pushButton->setIconSize(m_startbutton.size());

    //载入退出按钮图
    m_quitbutton.load(QUIT_BUTTON);
    ui->pushButton_2->move(GAME_WIDTH*0.5-80,GAME_HEIGHT*0.5);
    ui->pushButton_2->setText("");
    ui->pushButton_2->setIcon(m_quitbutton);
    ui->pushButton_2->resize(m_quitbutton.size());
    ui->pushButton_2->setMask(m_quitbutton.mask());
    ui->pushButton_2->setIconSize(m_quitbutton.size());

    //载入帮助按钮图
    m_helpbutton.load(HELP_BUTTON);
    ui->pushButton_3->move(GAME_WIDTH*0.5-80,GAME_HEIGHT*0.5+80);
    ui->pushButton_3->setText("");
    ui->pushButton_3->setIcon(m_helpbutton);
    ui->pushButton_3->resize(m_helpbutton.size());
    ui->pushButton_3->setMask(m_helpbutton.mask());
    ui->pushButton_3->setIconSize(m_helpbutton.size());

    //载入设置按钮图
    m_setbutton.load(SET_BUTTON);
    ui->pushButton_4->move(GAME_WIDTH*0.5-80,GAME_HEIGHT*0.5+160);
    ui->pushButton_4->setText("");
    ui->pushButton_4->setIcon(m_setbutton);
    ui->pushButton_4->resize(m_setbutton.size());
    ui->pushButton_4->setMask(m_setbutton.mask());
    ui->pushButton_4->setIconSize(m_setbutton.size());

    //载入英雄榜按钮图
    m_herobutton.load(HERO_BUTTON);
    ui->pushButton_5->move(GAME_WIDTH*0.5-80,GAME_HEIGHT*0.5+240);
    ui->pushButton_5->setText("");
    ui->pushButton_5->setIcon(m_herobutton);
    ui->pushButton_5->resize(m_herobutton.size());
    ui->pushButton_5->setMask(m_herobutton.mask());
    ui->pushButton_5->setIconSize(m_herobutton.size());

    //调用初始化场景接口
    Start::initScence();

    //绘制开始游戏界面
    Start::update();

    //帮助界面回到主界面连接函数
    connect(h,SIGNAL(backHelpsignal()),this,SLOT(backHelpSlots()));
    connect(s,SIGNAL(backsetSignal()),this,SLOT(backSetSlots()));
    connect(s,SIGNAL(bgmOnSignal()),this,SLOT(bgmOnSlots()));//开启背景音乐主界面
    connect(s,SIGNAL(bgmOffSignal()),this,SLOT(bgmOffSlots()));//关闭背景音乐主界面
    connect(s,SIGNAL(effectOnSignal()),this,SLOT(effectOnSlots()));//开启音效主界面
    connect(s,SIGNAL(effectOffSignal()),this,SLOT(effectOffSlots()));//开启音效主界面
    connect(w,SIGNAL(backMainscenceSignal()),this,SLOT(backMainscenceSlot()));//返回主届面

    //第二关返回
    connect(w->w2,SIGNAL(homeTwoSignal()),this,SLOT(homeTwoSlot()));
    //第三关返回
    connect(w->w2->w3,SIGNAL(homeThreeSignal()),this,SLOT(homeThreeSlot()));
}

Start::~Start()
{
    delete ui;
}

void Start::paintEvent(QPaintEvent *event)
{
    //在当前坐标中重新画画
    QPainter painter(this);

    //加载背景图
    painter.drawPixmap(0,0,m_background);
}

void Start::initScence()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));
    w->m_gamesound.m_start->play();

}

void Start::on_pushButton_clicked()
{

    w->ui->pushButton_2->show();
    w->ui->pushButton->show();
    w->m_hero.m_health=HERO_HEALTH;
    w->m_hero.m_energy=0;
    w->m_hero.m_X = (GAME_WIDTH - w->m_hero.m_Plane.width()) * 0.5;
    w->m_hero.m_Y = GAME_HEIGHT - w->m_hero.m_Plane.height();
    //w->m_gamesound.m_start->stop();
    for(int i = 0; i < ENEMY_NUM; i ++)
        {
            w->m_enemys[i].m_Free = true;
        }
        for(int i = 0; i < BULLET_NUM ; i ++)
        {
            w->m_hero.m_bullets[i].m_Free = true;
        }
        for(int i = 0; i < BULLET_NUM ; i ++)
        {
            w->m_hero.m_skill[i].m_free = false ;
        }
        for(int i = 0; i < BOMB_NUM ; i++)
            {
                w->m_bombs[i].m_Free = true ;
            }
        w->m_condition=0;
    w->m_leveltime=0;
    w->m_leveltips=true;
   // w->m_gamesound.m_bgm->play();
    w->move(this->x(),this->y());
    w->show();
    w->initScence();
    w->playGame();
    this->close();
    w->m_gamesound.m_start->stop();
    if(s->musicCheck==true)
    {
        w->m_gamesound.m_bgm->setVolume(0.5);
         w->m_gamesound.m_bgm->play();
    }
}

void Start::on_pushButton_2_clicked()
{
   this->close();
}

void Start::on_pushButton_4_clicked()
{
    s->move(this->x(),this->y());
    s->show();
    s->initscence();
    update();
    this->close();

}

void Start::on_pushButton_3_clicked()
{
    h->show();
        h->move(this->x(),this->y());
        h->initScence();
        h->setHelp();
        this->close();
}

void Start::backHelpSlots()
{
    //h->setAttribute(Qt::WA_DeleteOnClose);
       h->m_Timer->stop();
       this->show();
       this->move(h->x(),h->y());
       disconnect(h->m_Timer, SIGNAL(timeout()),h,SLOT(updateThis()));
       h->close();
}

void Start::backSetSlots()
{
    this->show();
    this->move(s->x(),s->y());

    s->close();
}

void Start::bgmOnSlots()
{
    w->m_gamesound.m_start->play();  //开始界面bgm起
    s->musicCheck=true;
}

void Start::bgmOffSlots()
{
    w->m_gamesound.m_start->stop();   //开始界面bgm关
    s->musicCheck=false;
}

void Start::effectOnSlots()
{
    w->m_gamesound.m_effect->setVolume(1);    //effect开
}

void Start::effectOffSlots()
{
    w->m_gamesound.m_effect->setVolume(0);    //effect关
}

void Start::backMainscenceSlot()
{
    w->m_Timer->stop();
    disconnect(w->m_Timer, SIGNAL(timeout()),w,SLOT(updateMainscence()));
    w->m_gamesound.m_bgm->stop();
    w->m_gamesound.m_start->play();
    w->hide();
    this->move(w->x(),w->y());
    this->show();

}

void Start::homeTwoSlot()
{
    w->w2->hide();
    this->move(w->w2->x(),w->w2->y());
    this->show();
}

void Start::homeThreeSlot()
{
    w->w2->w3->hide();
    this->move(w->w2->w3->x(),w->w2->w3->y());
    this->show();
}

/*void Start::toTwoLevel()
{
    w->m_Timer->stop();
    //disconnect(w->m_Timer, SIGNAL(timeout()),w,SLOT(updateMainscence()));  //断开连接
    w->hide();          //第一关窗口隐藏
    w2->move(w->x(),w->y());
    w2->initScence();   //初始化第二关
    w2->playGame();   //开始
    w2->show();
}*/
