. /etc/profile.d/java.sh            &&
chmod +x configure mkinstalldirs    &&

./configure  --build=${BUILD}       \
           --prefix=/usr            \
           --sysconfdir=/etc        \
           --localstatedir=/var     \
           --with-jdk=${JAVA_HOME}  \
           ${OPTS}                  &&
persistent_add MAKE_MODE=unix       &&
make
