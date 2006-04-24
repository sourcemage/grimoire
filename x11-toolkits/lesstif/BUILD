local sedtarget
for sedtarget in Makefile.in $(find doc -name Makefile.in); do
  sedit  's:$(prefix)/LessTif:$(prefix)/share/doc/lesstif:g'  $sedtarget
done  &&
export OPTS="$OPTS --enable-production --disable-debug --enable-static"    &&
export OPTS="$OPTS --enable-build-12 --enable-build-20 --enable-build-21"  &&
default_build
