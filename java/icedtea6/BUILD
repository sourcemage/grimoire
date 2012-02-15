export PATH_HOLD="${PATH}"                              &&
export JAVA_HOME="$BUILD_DIRECTORY/icedtea6-bin-1.10.4" &&
export CLASSPATH=".:/usr/share/java"                    &&
export PATH="${PATH}:${JAVA_HOME}/bin"                  &&

OPTS="$ICEDTEA6_DOCS $ICEDTEA6_OPT $ICEDTEA6_PARA $OPTS"             &&
OPTS="--with-tzdata-dir=/usr/share/zoneinfo $OPTS"                   &&
OPTS="--with-jdk-home=$BUILD_DIRECTORY/icedtea6-bin-1.10.4 $OPTS"    && 

unset JAVA_HOME &&

default_build
