# fix for gcc-3.4
#  sed -i "/^extern/d" scaffold.c                        &&
#  patch  -p 1  <  $SCRIPT_DIRECTORY/tcp_wrappers.patch  &&

if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]]; then
  # There are folks who want to link libwrap into shared objects.
  CFLAGS+=" -DPIC -fPIC "
fi  &&

# tcp_wrappers-7.6-shared_lib_plus_plus-1.patch changes "-O" to "-O2"
sedit 's/= -O2/= '"$CFLAGS"'/' Makefile  &&
make REAL_DAEMON_DIR=${INSTALL_ROOT}/usr/sbin STYLE=-DPROCESS_OPTIONS linux  
