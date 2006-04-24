unset  CFLAGS

if [ "$MMX" == "n" ]; then
  OPTS="--disable-mmx  ${OPTS}"
fi                                 &&

./configure  --build=$BUILD        \
             --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
             $OPTS                 &&
make
