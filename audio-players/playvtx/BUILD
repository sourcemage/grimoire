patch -p1 < $SCRIPT_DIRECTORY/libayemu.patch  &&
rm missing                                    &&
aclocal                                       &&
autoheader                                    &&
automake --add-missing --include-deps --copy  &&
autoconf                                      &&
default_build
