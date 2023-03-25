#include "set.h"
#include "ui_set.h"
#include"config.h"
#include<QIcon>
#include<QPainter>
#include<QBitmap>
#include<music.h>
#include<mainscence.h>
set::set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set)
{
    ui->setupUi(this);
    set_background.load(SET_BACKGROUND);//设置背景
    set_sound.load(SOUND_PATH);//设置声音图标

    set_soundbgmon.load(SOUND_BGMON);      //设置BGM开
    ui->pushButton->setIcon(set_soundbgmon);
    ui->pushButton->setText("");
    ui->pushButton->move(GAME_WIDTH*0.4+7,GAME_HEIGHT*0.4+10);
    ui->pushButton->resize(set_soundbgmon.size());
    ui->pushButton->setMask(set_soundbgmon.mask());
    ui->pushButton->setIconSize(set_soundbgmon.size());

    set_soundbgmoff.load(SOUND_BGMOFF);    //设置BGM开
    ui->pushButton_2->setIcon(set_soundbgmoff);
    ui->pushButton_2->setText("");
    ui->pushButton_2->move(GAME_WIDTH*0.4+13,GAME_HEIGHT*0.4+21);
    ui->pushButton_2->resize(set_soundbgmoff.size());
    ui->pushButton_2->setMask(set_soundbgmoff.mask());
    ui->pushButton_2->setIconSize(set_soundbgmoff.size());


    set_soundeffecton.load(SOUND_EFFECTON);      //设置effect开
    ui->pushButton_3->setIcon(set_soundeffecton);
    ui->pushButton_3->setText("");
    ui->pushButton_3->move(GAME_WIDTH*0.4+7,GAME_HEIGHT*0.4+78);
    ui->pushButton_3->resize(set_soundeffecton.size());
    ui->pushButton_3->setMask(set_soundeffecton.mask());
    ui->pushButton_3->setIconSize(set_soundeffecton.size());


    set_soundeffectoff.load(SOUND_EFFECTOFF);    //设置effect关
    ui->pushButton_4->setIcon(set_soundeffectoff);
    ui->pushButton_4->setText("");
    ui->pushButton_4->move(GAME_WIDTH*0.4+13,GAME_HEIGHT*0.4+89);
    ui->pushButton_4->resize(set_soundeffectoff.size());
    ui->pushButton_4->setMask(set_soundeffectoff.mask());
    ui->pushButton_4->setIconSize(set_soundeffectoff.size());

    set_back.load(SET_BACK);        //返回开关
    ui->pushButton_5->setIcon(set_back);
    ui->pushButton_5->setText("");
    ui->pushButton_5->move(GAME_WIDTH*0.2-33,GAME_HEIGHT*0.4);
    ui->pushButton_5->resize(set_back.size());
    ui->pushButton_5->setMask(set_back.mask());
    ui->pushButton_5->setIconSize(set_back.size());


}

set::~set()
{
    delete ui;
}

void set::initscence()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

}

void set::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,set_background);
    painter.drawPixmap(GAME_WIDTH*0.5-20,GAME_HEIGHT*0.4,set_sound);
}

void set::on_pushButton_clicked()
{
    emit bgmOffSignal();
}

void set::on_pushButton_2_clicked()
{
    emit bgmOnSignal();
}

void set::on_pushButton_3_clicked()
{
    emit effectOffSignal();
}

void set::on_pushButton_4_clicked()
{
    emit effectOnSignal();
}

void set::on_pushButton_5_clicked()
{
    emit(backsetSignal());
}
