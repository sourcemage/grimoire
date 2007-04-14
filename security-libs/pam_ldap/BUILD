if  !  [[ -x configure  ]]; then
  aclocal                            &&
  autoheader                         &&
  libtoolize  --copy  --force        &&
  automake  --add-missing            &&
  autoconf
fi  &&
OPTS="$OPTS --libdir=$INSTALL_ROOT/lib" &&
default_build
