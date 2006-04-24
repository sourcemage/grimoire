(

cd $SOURCE_DIRECTORY/src &&
export QTDIR=/usr &&

./configure --prefix=/usr \
	    $OPTS	&&

sedit "s/QTDIR)\/include/QTDIR)\/include\/qt/" Makefile &&
make && 
make install 


) > $C_FIFO 2>&1
