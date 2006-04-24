# Make sur /usr/lib/ladspa exists
mkdir -p $INSTALL_ROOT/usr/lib/ladspa &&
cd src &&
sedit 's:/usr/local:${INSTALL_ROOT}/usr:' makefile &&
make 
#20041007-bearcat m sandor- the make file wants to install the plugins
#to /usr/local/lib/ladspa/  but we want to install to /usr/lib/ladspa

