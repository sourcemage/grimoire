if list_find "$W3M_INLINE_IMAGE" "NONE" ; then
  OPTS="--enable-image=no $OPTS"
elif ! list_find "$W3M_INLINE_IMAGE" "AUTO" ; then
  W3M_INLINE_IMAGE="$(echo $W3M_INLINE_IMAGE | tr " " ",")"  &&
  OPTS="--enable-image=$W3M_INLINE_IMAGE $OPTS"
fi                                                           &&
OPTS="$W3M_OPTS --enable-keymap=$W3M_KEYMAP $OPTS"           &&
default_build
