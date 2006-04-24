(

patch -p0<$SCRIPT_DIRECTORY/dissoc.patch &&
./configure --prefix=/usr \
	    $OPTS	&&

make && 
make install

) > $C_FIFO 2>&1
