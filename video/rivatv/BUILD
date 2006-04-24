[ -e /dev/.devfsd ] && sedit "s/install: devices/install:/" Makefile.in

patch configure $SCRIPT_DIRECTORY/configure-fix.patch  &&
default_build
