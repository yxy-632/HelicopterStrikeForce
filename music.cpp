#include "music.h"
#include <QSound>
#include <QSoundEffect>
#include "config.h"
music::music()
{
    m_bgm = new QSoundEffect;
    m_effect = new QSoundEffect;
    m_start = new QSoundEffect;
    m_bgm->setSource(QUrl::fromLocalFile(SOUND_BACKGROUND));
    m_bgm->setLoopCount(SOUND_TIMES);
    m_start->setSource(QUrl::fromLocalFile(SOUND_START));
    m_start->setLoopCount(SOUND_TIMES);
    m_effect->setSource(QUrl::fromLocalFile(SOUND_BOMB));

}
