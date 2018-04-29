#include "xylotoyrc.h"
#include "lib/misulib/widgets/core/rootnotesetter.h"
#include "lib/misulib/widgets/core/scaleselect.h"
#include "lib/misulib/models/pitchcolor.h"

XylotoyRc::XylotoyRc(QObject *parent) : QObject(parent),
    _heartbeat(new Heartbeat(this))
{    

    for(int rootNote=0;rootNote<SCALE_SIZE+1;rootNote++) {
        _pitchColors.append(new PitchColor(rootNote,this));
    }

    for(int rootNote=0;rootNote<SCALE_SIZE+1;rootNote++) {
        RootNoteSetter * rootNoteSetter = new RootNoteSetter(rootNote,nullptr,this);
        connect(rootNoteSetter,SIGNAL(setRootNote(int)),_heartbeat,SLOT(onSetRootNote(int)));
        _rootNoteSetter.append(rootNoteSetter);
    }

    for(int i=0;i<SCALE_SIZE+1;i++) {
        for(int j=0;j<SCALE_SIZE+1;j++) {
            connect(_rootNoteSetter[i],SIGNAL(setRootNote(int)),_rootNoteSetter[j],SLOT(onSetRootNote(int)));
        }
    }

    QList<bool> scale;
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    _scaleSelect.append(new ScaleSelect("major",scale,this));

    scale.clear();
    scale.append(false);
    scale.append(true);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    scale.append(false);
    scale.append(true);
    _scaleSelect.append(new ScaleSelect("minor",scale,this));

    for(int i=0;i<_scaleSelect.size();i++) {
        connect(_scaleSelect.at(i),SIGNAL(setScale(QList<bool>)),_heartbeat,SLOT(onSetScale(QList<bool>)));
        for(int j=0;j<_scaleSelect.size();j++) {
            if(i!=j) {
                connect(_scaleSelect.at(i),SIGNAL(setScale(QList<bool>)),_scaleSelect.at(j),SLOT(onSetScale(QList<bool>)));
            }
        }
    }
}
