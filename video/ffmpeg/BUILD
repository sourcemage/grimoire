invoke_gcc
CFLAGS="${CFLAGS/-funroll-loops/}"
disable_pic  &&
if echo $CFLAGS | grep -q pentium4; then
  CFLAGS="${CFLAGS/-O3/} -O2"
fi

patch  -p1  <  $SCRIPT_DIRECTORY/gcc-3.4.patch  &&

sedit  's:-lpostproc:-Llibpostproc -lpostproc:'  libavcodec/Makefile  &&
./configure  --prefix=${INSTALL_ROOT}/usr            \
             --mandir=${INSTALL_ROOT}/usr/share/man  \
             --enable-shared                         \
             --enable-pp                             \
             --enable-shared-pp                      \
             --enable-gpl                            \
             --enable-a52                            \
             $OPTS                                   &&
sedit  's:SDL_LIBS=.*:\0 -L/usr/X11R6/lib -lX11:'  config.mak  &&
cd  libavcodec/libpostproc  &&
make                        &&
cd  $SOURCE_DIRECTORY       &&
make
