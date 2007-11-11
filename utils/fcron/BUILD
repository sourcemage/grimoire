create_account fcron

EDITOR=`which ${EDITOR%% *} 2> /dev/null` ||
EDITOR=`which nano`

sedit "s/-O2/$CFLAGS/" configure

./configure  --prefix=/usr          \
             --with-answer-all=no   \
	     --sysconfdir=/etc      \
             --with-editor=$EDITOR  \
             --bindir=/bin          \
             --sbindir=/sbin        \
             $OPTS                  &&
make
