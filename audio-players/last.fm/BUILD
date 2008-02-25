local PATH="/usr/bin/qt4:$PATH" &&
make_single &&
sedit "s/-ffast-math//" src/output/portAudio/Makefile &&
default_build &&
make_normal
