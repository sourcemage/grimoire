case "$HOST" in
*-musl)
  # The buildsystem assumes iconv is in libc
  export LIBS="-liconv"
  ;;
esac &&

default_build &&

if is_depends_enabled $SPELL perl; then
  cd "$SOURCE_DIRECTORY/AnyEvent-I3" &&
  
  default_build_perl                 &&
  
  cd "$SOURCE_DIRECTORY"
fi
