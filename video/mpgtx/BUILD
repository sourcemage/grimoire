sedit  's:gcc --version:gcc -dumpversion:'                     configure  &&
sedit  "s:/usr/local:${INSTALL_ROOT}/usr:"                     configure  &&
sedit  "s:^manprefix=.*:manprefix=${INSTALL_ROOT}/usr/share:"  configure  &&
sedit  "s:-ansi::"                                             configure  &&
sedit  "s:{};:{}:"                                             mpeg.cxx   &&
sedit  "s:inline::"                                            mpeg.cxx   &&
# non-standard configure
./configure --no-LFS  &&
make
