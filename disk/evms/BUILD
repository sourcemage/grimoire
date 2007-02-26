OPTS="--libdir=/lib
      --sbindir=/sbin
      ${OPTS}
" &&

# patch needed when compiling s390 support
patch -p1 < "${SCRIPT_DIRECTORY}/evms-2.5.1-s390.diff" &&

default_build
