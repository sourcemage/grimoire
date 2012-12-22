OPTS="$NBD_OPTS $OPTS" &&

default_build &&

if is_depends_enabled $SPELL zlib; then
  cd gznbd &&
  make &&
  cd $SOURCE_DIRECTORY
fi
