# Make sur /usr/lib/ladspa exists
mkdir -p $INSTALL_ROOT/usr/lib/ladspa &&
cd src &&
sedit 's:/usr/local:${INSTALL_ROOT}/usr:' makefile &&
sedit 's:-Werror::g' makefile &&
make 

