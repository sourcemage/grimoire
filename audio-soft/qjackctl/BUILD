(

patch -p0<$SCRIPT_DIRECTORY/qconf.patch &&
patch -p0<$SCRIPT_DIRECTORY/qjpro.patch &&

export QTDIR=/usr &&
./configure --prefix=/usr \
	    $OPTS	&&

make &&
make install

) > $C_FIFO 2>&1
