#ifndef XYLOTOYRC_H
#define XYLOTOYRC_H

#include <QObject>
#include "lib/misulib/comm/heartbeat.h"

class XylotoyRc : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> rootNoteSetter MEMBER _rootNoteSetter CONSTANT)
    Q_PROPERTY(QList<QObject*> scaleSelect MEMBER _scaleSelect CONSTANT)
    Q_PROPERTY(QList<QObject*> pitchColors MEMBER _pitchColors CONSTANT)

public:
    explicit XylotoyRc(QObject *parent = nullptr);

signals:

public slots:

private:
    Heartbeat*      _heartbeat;
    QList<QObject*> _rootNoteSetter;
    QList<QObject*> _scaleSelect;
    QList<QObject*> _pitchColors;

};

#endif // XYLOTOYRC_H
