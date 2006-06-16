OLD_CFLAGS="-Wall -O6 -fomit-frame-pointer -funroll-loops"  &&
sed -i "s/$OLD_CFLAGS/$CFLAGS/"  iv/platforms.ini  &&

./configure Linux --prefix=${INSTALL_ROOT}/usr  &&

if  spell_ok libungif; then  
	sed -i "s/lgif/lungif/" iv/Makefile
fi  &&
make all
