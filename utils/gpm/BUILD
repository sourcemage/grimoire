sedit  's/@EMACS@/:/'  Makefile.include.in                 &&
sedit  's/@ELISP@//'   Makefile.include.in                 &&
LDFLAGS="$LDFLAGS -lm"                                     &&
# Break circular dependency with ncurses
OPTS+=" --without-curses"                                  &&
./configure         --prefix=${TRACK_ROOT}/usr             \
                --sysconfdir=${TRACK_ROOT}/etc             \
             --localstatedir=${TRACK_ROOT}/var             \
                    --mandir=${TRACK_ROOT}/usr/share/man   \
                   --infodir=${TRACK_ROOT}/usr/share/info  \
             $OPTS                                         &&
sedit  "s/src doc contrib/src contrib/"  Makefile          &&
make_single  &&
make         &&
make_normal
