CFLAGS="${CFLAGS/-Os/} -I/usr/include/qt"
CXXFLAGS="${CXXFLAGS/-Os/} -I/usr/include/qt"
CLASSPATH="/opt/java-cup/java"           \
./configure --prefix=${INSTALL_ROOT}/usr \
        --sysconfdir=${INSTALL_ROOT}/etc \
     --localstatedir=${INSTALL_ROOT}/var \
            --mandir=${INSTALL_ROOT}/usr/share/man \
           --infodir=${INSTALL_ROOT}/usr/share/info \
              --host=$HOST \
	   $OPTS &&
make
