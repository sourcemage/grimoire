if [[ "$MUMBLE_SERVER" == 'n' ]]; then
    OPTS+=" -Dserver=off"
else
    OPTS+=" -Dserver=on"
fi

if [[ "$MUMBLE_CLIENT" == 'n' ]]; then
    OPTS+=" -Dclient=off"
else
    OPTS+=" -Dclient=on"
fi

OPTS+=" -Dbundle-qt-translations=off" &&
OPTS+=" -Dupdate=off"                 &&
OPTS+=" -Doverlay=off"                &&
OPTS+=" -Dbundled-celt=on"            &&
OPTS+=" -Dwarnings-as-errors=off"     &&

default_build
