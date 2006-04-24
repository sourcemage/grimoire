if echo ${OPTS} | grep -q tk; then
   export LDFLAGS="$LDFLAGS -L /usr/X11R6/lib"
fi                                              &&

OPTS="--with-tcl=/usr/lib                       \
      ${OPTS}"                                  &&

make_single                                     &&
default_build
