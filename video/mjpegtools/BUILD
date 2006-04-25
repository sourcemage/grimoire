# fix bug #6403
sedit  's/ARCHFLAGS="-mcpu=i786 -march=$arch"/ARCHFLAGS=""/'  configure  &&
sedit  's/ARCHFLAGS="-mcpu=i686 -march=$arch"/ARCHFLAGS=""/'  configure  &&
sedit  's/ARCHFLAGS="-mcpu=i586 -march=$arch"/ARCHFLAGS=""/'  configure  &&

# fails to compile with -DPIC and -fPIC except on AMD64
disable_pic  &&

OPTS="--without-libquicktime $OPTS"  &&
make_single                                                   &&
default_build                                                 &&
make_normal
