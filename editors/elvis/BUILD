OPTS="--verbose $OPTS" &&

sedit  "s/-O2/$CFLAGS/"  configure                      &&
# corrected manuals installation
sedit "s:\/usr\/local:${INSTALL_ROOT}\/usr:" instman.sh &&
sedit "s:${PREFIX}\/man:${PREFIX}\/share\/man:" instman.sh &&

OPT=`echo "${OPTS} linux"`                              &&
default_build

