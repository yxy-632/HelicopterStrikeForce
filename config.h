#ifndef CONFIG_H
#define CONFIG_H
//制作人：林世炜，闫新禹


/**********  开始界面配置数据 **********/
#define START_BACKGOURND ":/res/start_2.png"   //开始界面背景图
#define START_BUTTON ":/res/startbutton.png" //开始按钮设置
#define QUIT_BUTTON ":/res/quitbutton.png" //开始按钮设置
#define HELP_BUTTON ":/res/helpbutton.png" //开始按钮设置
#define SET_BUTTON ":/res/setbutton.png" //开始按钮设置
#define HERO_BUTTON ":/res/herobutton.png" //开始按钮设置

/**********  设置界面配置数据 **********/
#define SOUND_PATH ":/res/sound1.png"  //音量图标
#define SOUND_BGMON ":/res/soundon.png"  //BGM打开
#define SOUND_BGMOFF ":/res/soundoff.png"  //关闭
#define SOUND_EFFECTON ":/res/soundon.png"  //effect打开
#define SOUND_EFFECTOFF ":/res/soundoff.png"  //effect关闭
#define SET_BACK ":/res/backbutton.png"     //返回按键
#define SET_BACKGROUND ":/res/set_background.png"

/**********  帮助界面图标配置数据 **********/
#define HELP_BACKGOURND ":/res/help_background.png"   //帮助界面背景图
#define HELP_HREO ":/res/hero3.png"          //帮助敌机设置
#define BACK_BUTTON ":/res/backbutton.png"  //返回按钮设置

/**********  过关条件数据配置 **********/
#define FIRST_CONDITION 120  //过关卡1条件，击败敌机数量
#define TWO_CONDITION 500  //过关卡二条件，生存的时间

/**********  游戏界面图标配置数据 **********/
#define GAME_QUIT  ":/res/w_quit.png"   //暂停按钮
#define GAME_START ":/res/w_start.png"   //开始按钮
#define GAME_SET ":/res/w_set.png"  //设置按钮
#define GAME_HELP ":/res/w_help.png"   //帮助
#define GAME_LEVELTIPS ":/res/leveltips"  //关卡1提示图标
#define GAME_LEVELTIPS2 ":/res/leveltips2"  //关卡2提示图标
#define GAME_LEVELTIPS3 ":/res/leveltips3"  //关卡提示图标
#define GAME_LEVELTIME 800 //关卡提示时间长度
#define GAME_LOSEFLAG ":/res/loseflag.png"  //失败图标
#define GAME_WINFLAG ":/res/winflag.png" //胜利图标
/**********  游戏边框配置数据 **********/
#define GAME_WIDTH  512  //宽度
#define GAME_HEIGHT 768  //高度
#define GAME_TITLE "鹰击长空 v1.0" //标题
#define GAME_ICON ":/res/Icon.png"  //图标路径
#define GAME_RATE  5  //定时器刷新时间间隔 单位毫秒

/**********  游戏地图配置数据 **********/
#define MAP_PATH ":/res/img_bg_level_3.jpg" //第一关地图路径
#define MAP_PATH2 ":/res/img_bg_level_5.jpg" //第二关地图路径
#define MAP_PATH3 ":/res/img_bg_level_4.jpg" //第三关地图路径
#define MAP_SCROLL_SPEED 1   //地图滚动速度

/**********  飞机配置数据 **********/
#define HERO_PATH ":/res/hero2.png"
#define HERO_HEALTH 4  //飞机生命值设置
#define HERO_BLOOD1 ":/res/blood.png"  //空血状态
#define HERO_BLOOD2 ":/res/blood2.png"  //一血状态
#define HERO_BLOOD3 ":/res/blood3.png"  //二血状态
#define HERO_BLOOD4 ":/res/blood4.png"  //三血状态
#define HERO_BLOOD5 ":/res/blood5.png"  //满血状态
#define LOSE_BLOOD 1  //丢失血量
#define HERO_ENERGY 4// 飞机能量值设置
#define HERO_ENERGY1 ":/res/energy1.png" //能量值1
#define HERO_ENERGY2 ":/res/energy2.png" //能量值2
#define HERO_ENERGY3 ":/res/energy3.png" //能量值3
#define HERO_ENERGY4 ":/res/energy4.png" //能量值4
#define HERO_ENERGY5 ":/res/energy5.png" //能量值5
#define UP_ENERGY 0.25   //增加能量
#define SKILL_INTERVAL 1000  //大招持续时长
#define SKILL_BULLET ":/res/bullet_15.png" //大招所用子弹


/**********  子弹配置数据 **********/
#define BULLET_PATH ":/res/bullet_11.png"   //子弹图片路径
#define BULLET_SPEED 2  //子弹移动速度
#define BULLET_NUM 30   //弹匣中子弹总数
#define BULLET_INTERVAL 50 //发射子弹时间间隔


/**********  敌机配置数据 **********/
#define ENEMY_PATH  ":/res/img-plane_5.png"  //敌机资源图片
#define ENEMY_SPEED 1  //敌机移动速度fine
#define ENEMY_NUM   20  //敌机总数量
#define ENEMY_INTERVAL  70  //敌机出场时间间隔

/**********  敌机2配置数据 **********/
#define ENEMY2_PATH ":/res/img-plane_1.png" //敌机2资源图片
#define ENEMY2_SPEED 1 //敌机2移动速度
#define ENEMY2_NUM   20  //敌机2总数量
#define ENEMY2_INTERVAL  70  //敌机出场时间间隔
#define ENEMY2_BULLETPATH ":/res/bullet_5.png"  //敌机2子弹图片

/**********  boss配置数据 **********/
#define BOSS_PATH ":/res/boss2.png" //boss资源图片
#define BOSS_BLOOD1 ":/res/bossblood1.png" //boss血条图片1
#define BOSS_BLOOD2 ":/res/bossblood2.png" //boss血条图片2
#define BOSS_BLOOD3 ":/res/bossblood3.png" //boss血条图片3
#define BOSS_BLOOD4 ":/res/bossblood4.png" //boss血条图片4
#define BOSS_BLOOD5 ":/res/bossblood5.png" //boss血条图片5
#define BOSS_BLOOD6 ":/res/bossblood6.png" //boss血条图片6
#define BOSS_BLOOD7 ":/res/bossblood7.png" //boss血条图片7
#define BOSS_HEALTH 7  //boss血量
#define BOSS_BULLET ":/res/bullet_6.png"  //boss子弹图片
#define BOSS_SPEED 2 //子弹速度
#define BOSS_INTERVAL 150 //射击子弹间隔

/**********  道具配置数据 **********/
#define PROP_BLOOD ":/res/propblood.png"  //血包
#define PROP_BLOODUP 2  //血包增加血量
#define PROP_BLOODSPEED 2  //血包移动速度
#define PROP_BLOODNUM 20  //血包库数量

/**********  爆炸配置数据 **********/
#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 10   //爆炸切图时间间隔

/**********  音效配置数据 **********/
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"
#define SOUND_START ":/res/startbgm.wav"  //游戏主界面背景音乐
#define SOUND_TIMES 5    //背景音乐循环次数
#define SOUND_VOLUME 1   //音量大小
#endif // CONFIG_H
