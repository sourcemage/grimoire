OPTS="--disable-dependency-tracking $OPTS"  &&

default_build  &&

.  "$GRIMOIRE/is_depends_enabled.function"  &&

if  is_depends_enabled  $SPELL  doxygen
then
  make  docs
fi
