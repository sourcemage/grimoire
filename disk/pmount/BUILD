if [[ $CRYPT  == "y" ]]; then
	CRYPTSETUP=`which cryptsetup`				&&
	sed -i -e "s|/sbin/cryptsetup|$CRYPTSETUP|" src/policy.h 
fi  &&
default_build
