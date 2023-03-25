#ifndef SET_H
#define SET_H

#include <QWidget>
#include<QPixmap>
namespace Ui {
class set;
}

class set : public QWidget
{
    Q_OBJECT

public:
    explicit set(QWidget *parent = nullptr);
    ~set();
public:
    void initscence();
    void paintEvent(QPaintEvent *event);

    QPixmap set_background;
    QPixmap set_sound;
    QPixmap set_soundbgmon;
    QPixmap set_soundbgmoff;
    QPixmap set_soundeffecton;
    QPixmap set_soundeffectoff;
    QPixmap set_back;
    //游戏声音判断
    bool musicCheck=true;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

signals:
    void backsetSignal();
    void bgmOnSignal();    //背景音乐开启信号
    void bgmOffSignal();   //背景音乐关闭信号
    void effectOnSignal(); //音效开启信号
    void effectOffSignal();//音效关闭信号
private:
    Ui::set *ui;
};

#endif // SET_H
