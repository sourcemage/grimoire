# FIXME -D_XOPEN_SOURCE >= 500 required for setgrent
# FIXME -D_POSIX_C_SOURCE >= 200112L required for setenv/unsetenv
# maybe other portability issues
CFLAGS+=" -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=600" &&
./configure --prefix="$INSTALL_ROOT"/usr &&
make -j "$MAKE_NJOBS"
