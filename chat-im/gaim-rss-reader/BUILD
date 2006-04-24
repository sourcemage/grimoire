CFLAGS="-I/usr/include/libxml2/ $CFLAGS"
# if  [  "$CVS"  ==  "y"  ] ;  then ./autogen.sh; fi   &&
./configure  --build=$BUILD                     \
             --prefix=/usr                      \
             --sysconfdir=/etc                  \
             --localstatedir=/var               \
             --with-gaim=/usr/include/gaim      \
             $OPTS                              &&
make_single  &&
make         &&
make_normal
