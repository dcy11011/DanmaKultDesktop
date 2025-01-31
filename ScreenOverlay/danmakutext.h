#ifndef DANMAKUTEXT_H
#define DANMAKUTEXT_H

#include <QObject>
#include <QPointF>
#include <QPainter>



class DanmakuText : public QObject
{
    Q_OBJECT

protected:
    QPointF     m_pos, m_vel; // position and velocity
    QString     m_text;
    QColor      m_color;
    QRect       m_bound;

    bool        m_boundReady;
    bool        m_delTag;
    int         m_id;

public:
    explicit DanmakuText(QObject *parent = nullptr);

    bool setText(const QString &text);

    bool setPos(const QPointF &pos);
    bool setVel(const QPointF &vel);
    bool setColor(const QColor &color);
    bool setID(int id);
    void del();

    QPoint pos() const;
    QPointF posF() const;

    QRect bound() const;
    bool  boundReady() const;

    int id() const;

public:
    virtual bool paint(QPainter *painter);
    virtual bool update();
    virtual void calcBound(QPainter *painter);

signals:

};

#endif // DANMAKUTEXT_H
