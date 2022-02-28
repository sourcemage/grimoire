if [ "$DJGPP_BINUTILS_LTO" = y ];then
  OPTS+=" --enable-lto"
fi &&

disable_fortify_source &&

mkdir  buildit &&
cd     buildit &&

tooldir="$INSTALL_ROOT"/usr/lib/djgpp &&
../configure  --host=$HOST                  \
              --build=$BUILD                \
	      --target="i386-pc-msdosdjgpp" \
              --prefix="$INSTALL_ROOT"/usr  \
	      --libdir="$tooldir"/lib       \
              --mandir="$TRACK_ROOT"/usr/share/man \
	      --datarootdir="$INSTALL_ROOT"/usr/share/djgpp \
              --disable-werror              \
              --enable-ld                   \
              --enable-gold                 \
              $OPTS &&
make -j"$MAKE_NJOBS" tooldir="$tooldir"
