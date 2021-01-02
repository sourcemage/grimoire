if is_depends_enabled $SPELL libtommath; then
  make -f makefile.shared CFLAGS=" -DUSE_LTM -DLTM_DESC"
else
  make -f makefile.shared
fi &&
if is_depends_enabled $SPELL texlive; then
  make docs
fi
