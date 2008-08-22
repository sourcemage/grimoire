#OPTS=${OPTS/--without-system-utf8-funcs}            &&
#OPTS=${OPTS/--disable-dictorg}                      &&
#OPTS=${OPTS/--enable-plugin}                        &&
if [[ $DICTD_REGEXP == tre ]] ; then
LDFLAGS='-ltre'
fi                                                  &&
if [[ $DICTD_REGEXP == pcre ]] ; then
LDFLAGS='-lpcre -lpcreposix'                        &&
OPTS="--with-regex-include='pcreposix.h' $OPTS"
fi                                                  &&
if [[ $DICTD_REGEXP == builtin ]] ; then
OPTS="--with-local-regex $OPTS"
fi                                                  &&
OPTS="$DICTD_OPTS $OPTS"                            &&
OPTS="--build=${BUILD} $OPTS"                       &&
[[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

./configure --prefix=${TRACK_ROOT}/usr              \
            --sysconfdir=${TRACK_ROOT}/etc          \
            --localstatedir=${TRACK_ROOT}/var       \
            --mandir=${TRACK_ROOT}/usr/share/man    \
            --infodir=${TRACK_ROOT}/usr/share/info  \
            $OPTS                                   &&
make_single                                         &&
if list_find $DICTD_BUILD "client"
then
  make dict colorit dictzip dictfmt plugins
elif list_find $DICTD_BUILD "server"
then
  make dictd plugins
else
  make
fi                                                  &&
make_normal
