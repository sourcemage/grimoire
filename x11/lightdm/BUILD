create_account lightdm                                               &&

OPTS+=" --disable-static"                                            &&
OPTS+=" --disable-tests"                                             &&
OPTS+=" --with-user-session=lightdm-xsession"                        &&
OPTS+=" --with-greeter-user=lightdm"                                 &&
OPTS+=" --with-html-dir=${INSTALL_ROOT}/usr/share/doc/${SPELL}/html" &&

QTDIR="${QTDIR:-$INSTALL_ROOT/usr}" PATH="$QTDIR/bin/qt4:$PATH" default_build
