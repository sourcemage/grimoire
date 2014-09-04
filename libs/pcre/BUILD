OPTS+=" --disable-static $JIT $PCRE8 $PCRE16" &&
if [[ $BUILDUTF == y ]]; then
   OPTS="$OPTS --enable-utf"
  if [[ $UTFPROPERTIES == y ]]; then
    OPTS="$OPTS --enable-unicode-properties"
  fi
 
fi &&

default_build
