sedit  's/@EMACS@/:/'  Makefile.include.in         &&
sedit  's/@ELISP@//'   Makefile.include.in         &&
LDFLAGS="$LDFLAGS -lm"                             &&
./configure  --prefix=/usr  $OPTS                  &&
sedit  "s/src doc contrib/src contrib/"  Makefile  &&
make
