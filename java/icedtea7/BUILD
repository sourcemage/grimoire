export PATH_HOLD="${PATH}"                               &&
export JAVA_HOME="$BUILD_DIRECTORY/icedtea-bin-7.2.3.6"  &&
export CLASSPATH=".:/usr/share/java"                     &&
export PATH="${PATH}:${JAVA_HOME}/bin"                   &&

OPTS="$ICEDTEA7_DOCS $ICEDTEA7_OPT $ICEDTEA7_PARA $OPTS"                            &&
OPTS="--with-jdk-home=$BUILD_DIRECTORY/icedtea-bin-7.2.3.6 $OPTS"                   && 
OPTS="--with-abs-install-dir=${INSTALL_ROOT}/usr/lib/icedtea7-$VERSION $OPTS"       &&
OPTS="--disable-bootstrap --disable-downloading $OPTS"                              &&

unset JAVA_HOME &&

default_build
