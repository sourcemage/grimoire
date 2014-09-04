# fails to compile with -DPIC and -fPIC (except on all-PIC archs)
disable_pic &&
CFLAGS+=" -fpermissive"   &&
CXXFLAGS+=" -fpermissive" &&

make_single                                                   &&
default_build                                                 &&
make_normal
