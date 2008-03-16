OPTS="--disable-asio-driver --disable-mmemidi-driver           \
      --disable-coremidi-driver --disable-dependency-tracking  \
      $LS_ASM $OPTS"  default_build                            &&

if  is_depends_enabled  $SPELL  doxygen
then
  make  docs
fi
