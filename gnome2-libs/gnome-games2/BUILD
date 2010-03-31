if [[ $GGAMES_PRESET == pick ]]; then
 OPTS="--enable-games=$GGAMES_LIST $OPTS"
else
 OPTS="--enable-games=$GGAMES_PRESET $OPTS"
fi                                                               &&

OPTS="--with-scores-group=games --with-scores-user=games $OPTS"  &&
OPTS="$GGAMES_ANL $OPTS"                                         &&

default_build
