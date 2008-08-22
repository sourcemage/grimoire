sedit 's:for lib in lib out:for lib in "" lib out:' configure  &&
sedit 's:/local::'                                  configure  &&

sedit 's:mandir=man:mandir=share/man:'           doc/Makefile  &&
sedit 's:QTDIR/bin/:QTDIR/bin/qt4:'              configure     &&
sedit 's:/qt/Qt /qt4/Qt:/Qt:'                    configure     &&

export QTDIR="/usr"                                            &&
export PATH=${TRACK_ROOT}/usr/bin/qt4:$PATH                    &&

./configure                                                    &&
make
