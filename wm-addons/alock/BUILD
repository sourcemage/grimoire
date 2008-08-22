cd $SOURCE_DIRECTORY                          &&

if [[ "${ALOCK_SHADOW}" = "y" ]]; then
    OPTS="${OPTS} --with-passwd"
fi                                            &&

OPTS="${OPTS} ${ALOCK_OPTS}"                  &&
./configure --prefix $INSTALL_ROOT/usr $OPTS  &&
make
