create_account  fcron

# Removed according to Bug #385
# if    spell_ok  linux-pam
# then  WITH_PAM="--with-pam=yes"
# else  WITH_PAM="--with-pam=no"
# fi
WITH_PAM="--with-pam=no"

EDITOR=`which ${EDITOR%% *}  2>/dev/null`  ||
EDITOR=`which nano`

sedit  "s/-O2/$CFLAGS/"  configure

./configure  --prefix=/usr          \
             --with-answer-all=no   \
             $WITH_PAM              \
             --with-editor=$EDITOR  \
             --bindir=/bin          \
             --sbindir=/sbin        \
             $OPTS                  &&
make
