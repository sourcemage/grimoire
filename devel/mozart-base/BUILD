#the bison and flex checks were seriously borked, I patch the configure
export YACC=yacc                                               &&
patch -p1 < $SCRIPT_DIRECTORY/mozart.patch                     &&
./configure  \
    --host=$HOST \
    --build=$BUILD \
    --prefix=/usr/lib/oz \
    --bindir=/usr/bin \
    --sysconfdir=/etc \
    --localstatedir=/var \
    --enable-opt=yes \
    --enable-threaded \
    --enable-fastreg \
    --enable-regopt \
    --disable-modules-static \
    --enable-contrib \
    --disable-chm \
    $OPTS &&

make_single  &&
make         &&
make_normal
