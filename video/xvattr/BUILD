./configure  $OPTS  &&
make  xvattr        &&

#
## Remove this after is_depends_enabled is integrated to stable sorcery.
#
source  "$GRIMOIRE/is_depends_enabled.function"  &&

if is_depends_enabled $SPELL gtk+;  then
  make gxvattr
fi
