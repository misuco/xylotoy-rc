#include "xylotoyrc.h"
#include "lib/misulib/widgets/core/rootnotesetter.h"
#include "lib/misulib/models/pitchcolor.h"

XylotoyRc::XylotoyRc(QObject *parent) : QObject(parent)
{
    _heartbeat = new Heartbeat(this);

    for(int rootNote=0;rootNote<SCALE_SIZE+1;rootNote++) {
        _pitchColors.append(new PitchColor(rootNote,this));
    }

    for(int rootNote=0;rootNote<SCALE_SIZE+1;rootNote++) {
        RootNoteSetter * rootNoteSetter = new RootNoteSetter(rootNote,nullptr,this);
        connect(rootNoteSetter,SIGNAL(setRootNote(int)),_heartbeat,SLOT(onSetRootNote(int)));
        _rootNoteSetter.append(rootNoteSetter);
    }
}
