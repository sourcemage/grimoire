invoke_gcc
#patch  -p1  <  $SCRIPT_DIRECTORY/cinelerra-2.0-shared.patch  &&
# random options generate random crashes, the only ones that work reliably for
# me are the defaults cinelerra build uses
# fixes part of bug #10772
unset CFLAGS    &&
unset CXXFLAGS  &&
unset LDFLAGS   &&
# disable fortran detection for fftw, fixes part of bug #10772
sedit  's:CFLAGS=-fPIC ./configure:\0 --disable-fortran:' configure  &&
# non-gnu configure
./configure  &&
make

