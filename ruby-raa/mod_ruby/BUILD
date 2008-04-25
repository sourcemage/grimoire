OPTS="$OPTS --with-apr-includes=placeholder"
./configure.rb --prefix=${INSTALL_ROOT}/usr \
               --mandir=${INSTALL_ROOT}/usr/share/man \
                        $OPTS &&
sed -i -e "s,-Iplaceholder,$(apr-config --includes) $(apu-config --includes)," Makefile &&
default_build_make
