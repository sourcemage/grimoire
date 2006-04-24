#
# Adding "-D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64"
# to the CFLAGS of Python's compile should fix the
# no large-file support warning, but I'm not sure what
# that'd do on systems that don't support >2Gb
# See: http://www.python.org/doc/current/lib/posix-large-files.html
#
./configure  --prefix=${INSTALL_ROOT}/usr/lib/zope       \
             --with-python=$INSTALL_ROOT/usr/bin/python  \
             --ignore-largefile                          &&
make

