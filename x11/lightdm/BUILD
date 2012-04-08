create_account lightdm                                               &&

OPTS+=" --disable-liblightdm-qt"                                     &&
OPTS+=" --disable-static"                                            &&
OPTS+=" --with-user-session=lightdm-xsession"                        &&
OPTS+=" --with-greeter-session=lightdm-gtk-greeter"                  &&
OPTS+=" --with-greeter-user=lightdm"                                 &&
OPTS+=" --with-html-dir=${INSTALL_ROOT}/usr/share/doc/${SPELL}/html" &&

default_build
