if [ "$PYT" == "y" ];
then
    MYCONF="$MYCONF --enable-python "                                       &&
    message "${MESSAGE_COLOR}Enable python module building${DEFAULT_COLOR}" 
fi                                                                          &&
if [ "$LDEBUG" == "y" ];
then
    MYCONF="$MYCONF --enable-debug"                                         &&
    message "${MESSAGE_COLOR}Enable debug code${DEFAULT_COLOR}" 
fi                                                                          &&

real_sedit "s/^libledger_a_CXXFLAGS.*$/libledger_a_CXXFLAGS\=\-I\/usr\/include\/w3c-libwww/" \
    Makefile.am                                                             &&

aclocal                                                                     &&
autoheader                                                                  &&
libtoolize --force --copy                                                   &&
aclocal                                                                     &&
autoconf                                                                    &&
automake --foreign --add-missing --copy                                     &&

OPTS="$OPTS $MYCONF"                                                        &&
default_build

make
