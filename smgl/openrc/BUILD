cd $SOURCE_DIRECTORY &&
OPTS+=" DESTDIR=$INSTALL_ROOT" &&
#OPTS+=" DESTDIR=$INSTALL_ROOT/opt/openrc" &&
#OPTS+=" DESTDIR=/tmp/openrc-image" &&
#OPTS+=" MKPREFIX=yes" &&
#OPTS+=" PREFIX=/opt/openrc" &&
OPTS+=" BRANDING=\"SourceMage$(uname -s)\"" &&
OPTS+=" MKBASHCOMP=yes" &&
OPTS+=" MKPKGCONFIG=yes" &&
OPTS+=" MKNET=yes" &&
OPTS+=" LIBNAME=lib" &&
#OPTS+="" &&
make $OPTS
