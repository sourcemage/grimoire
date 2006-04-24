PREFIX=/usr                       &&
DATADIR=${PREFIX}/share/${SPELL}  &&
OPTS="--prefix=$PREFIX            \
      --datadir=${DATADIR}        \
      $OPTS"                      &&
make_single                       &&
default_build                     &&
sedit "s:/local::" src/qhacc
