sedit  "s/-O2/$CXXFLAGS/"  unix/Makefile.in
cd  builds
../unix/configure  --build=$BUILD        \
                   --prefix=/usr         \
                   --sysconfdir=/etc     \
                   --localstatedir=/var  \
                   $OPTS                 &&
make
