local MYCONF=""

if [ "$USE_SNMPTRAP" == "n" ];
then
    MYCONF="$MYCONF --disable-snmptrap "                                      &&
    message "${MESSAGE_COLOR}Disable snmptrap sending support${DEFAULT_COLOR}"
else
    message "${MESSAGE_COLOR}Enable snmptrap sending support${DEFAULT_COLOR}"
fi                                                                            &&

OPTS="$OPTS $MYCONF"                                                          &&

default_build
