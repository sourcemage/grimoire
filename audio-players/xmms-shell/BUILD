if [ "$WITH_READLINE" == "y" ] ; then
	patch  -p0  <  ${SCRIPT_DIRECTORY}/readline.patch   &&
	aclocal                                             &&
	autoheader                                          && 
	automake --add-missing --copy                       &&
	autoconf
fi &&
default_build
