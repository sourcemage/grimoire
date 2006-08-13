(

export QTDIR=/usr  &&
sed -e 's/QTDIR\/include/QTDIR\/include\/qt/g' -i configure &&
./configure --prefix=/usr \
	    $OPTS       &&
make &&
make install

) > $C_FIFO 2>&1
