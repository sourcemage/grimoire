create_account lightdm                                               &&

OPTS+=" --disable-dependency-tracking"                               &&
OPTS+=" --disable-static"                                            &&
OPTS+=" --disable-tests"                                             &&
OPTS+=" --with-user-session=lightdm-xsession"                        &&
OPTS+=" --with-greeter-user=lightdm"                                 &&
OPTS+=" --with-html-dir=${INSTALL_ROOT}/usr/share/doc/${SPELL}/html" &&

if is_depends_enabled $SPELL qtbase;then
  export PKG_CONFIG_PATH="$QT5DIR/lib/pkgconfig"
  export PATH+=":$QT5DIR/bin"
fi &&

default_build
