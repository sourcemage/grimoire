sedit 's:/usr/local/sbin:/usr/sbin:g' Makefile &&
cp defconfig .config &&
if [[ $RECONFIGURE ]] && [[ $CONFIG_EDIT == "y" ]]
then
	$EDITOR .config
fi &&
make
