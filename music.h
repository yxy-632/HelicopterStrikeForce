#ifndef MUSIC_H
#define MUSIC_H
#include <QSound>
#include <QSoundEffect>
class music
{
public:
    music();
public:
    QSoundEffect * m_bgm;
    QSoundEffect * m_start;
    QSoundEffect * m_effect;
};

#endif // MUSIC_H
