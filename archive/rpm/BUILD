export LDFLAGS=${LDFLAGS/-z combreloc/} &&
OPTS="$OPTS $RPM_API $RPM_SELINUX --disable-static --with-libintl-prefix=/usr"      &&
#export CPPFLAGS="$CPPFLAGS -I/usr/include/python$(installed_version python| cut -c 1-3)" &&
default_build
