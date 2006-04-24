if [[ $CRYPT  == "y" ]]; then
	CRYPTSETUP=`which cryptsetup`				&&
	sed -i -e "s|/sbin/cryptsetup|$CRYPTSETUP|" policy.h 
fi
make
