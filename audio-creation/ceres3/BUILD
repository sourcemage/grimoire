(

cd $SOURCE_DIRECTORY &&

if (uname -m | grep 86) 
then
	cd tichstuff_ix86 &&
	make &&
	cd .. &&
	make -f makefile.linux_ix86
elif (uname -m | grep ppc)
then
	cd tichstuff_ppc &&
	make &&
	cd .. &&
	make -f makefile.linux_ppc
else
	echo "Unknown arch..."
fi

cp ceres3 /usr/bin/ceres3


) > $C_FIFO 2>&1
