sedit 's:for lib in lib out:for lib in "" lib out:' configure  &&
sedit 's:/local::'                                  configure  &&

sedit 's:mandir=man:mandir=share/man:'           doc/Makefile  &&

export QTDIR="/usr/lib/qt4"                  &&
export PATH=${TRACK_ROOT}/usr/bin/qt4:$PATH  &&

./configure                                  &&
make
