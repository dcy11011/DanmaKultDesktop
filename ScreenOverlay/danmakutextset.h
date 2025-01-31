#ifndef DANMAKUTEXTSET_H
#define DANMAKUTEXTSET_H

#include <QObject>
#include <list>
#include <queue>

#include "danmakutext.h"

const int DANMAKU_RAIL_CNT = 14;
const int DANMAKU_TEXT_INTERVAL = 30;

class DanmakuTextSet : public QObject
{
    Q_OBJECT
public:
    explicit DanmakuTextSet(QObject *parent = nullptr);
    bool append(std::shared_ptr<DanmakuText> text);
    bool setBound(const QRect &r);

protected:
    virtual int getRailCnt();
    virtual int calcRailYpos();
    virtual int popWaiting();
    virtual int updateRailStatus();
    virtual bool ifBlockRail(const DanmakuText &text, int railID);
    virtual void pushToRail(DanmakuText &text, int railID);

protected:
    std::list<std::shared_ptr<DanmakuText>> m_texts;
    QRect m_bound;

    std::queue<std::shared_ptr<DanmakuText>> m_waiting;
    int m_railYpos[DANMAKU_RAIL_CNT];
    bool m_ifRailFree[DANMAKU_RAIL_CNT];
    int m_nAvailableRail;


public:
    bool paint(QPainter *painter);
    bool update();

signals:

};

#endif // DANMAKUTEXTSET_H
