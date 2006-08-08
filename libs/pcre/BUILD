if [ "$BUILDUTF8" == "y" ] ; then
   OPTS="$OPTS --enable-utf8"
  if [ "$UTFPROPERTIES" == "y" ] ; then
    OPTS="$OPTS --enable-unicode-properties    "
  fi
 
fi &&

make_single    &&
default_build  &&
make_normal
