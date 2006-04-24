if  !  [[ -x configure  ]]; then
  aclocal                            &&
  autoheader                         &&
  libtoolize  --copy  --force        &&
  automake  --add-missing            &&
  autoconf
fi  &&
default_build
