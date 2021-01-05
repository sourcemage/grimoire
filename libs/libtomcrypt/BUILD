if is_depends_enabled $SPELL libtommath; then
  CFLAGS+=" -DUSE_LTM -DLTM_DESC"
fi &&
make -f makefile.shared &&
if is_depends_enabled $SPELL texlive; then
  make docs
fi
