if [[ $CRYPT  == "y" ]]; then
	sed -i -e "s|/sbin/cryptsetup|`which cryptsetup`|" src/policy.h
fi  &&
default_build
