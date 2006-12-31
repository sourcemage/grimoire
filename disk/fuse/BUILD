if [[ $CVS == y ]]
then
  OPTS="$OPTS --disable-mtab"
fi &&
OPTS="$OPTS --with-kernel=$INSTALL_ROOT/usr/src/linux-$(get_kernel_version)" &&
default_build
