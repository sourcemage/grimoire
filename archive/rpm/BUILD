WITH_DB_SUBDIR=/usr/lib  &&
persistent_add LDFLAGS=${LDFLAGS/-z combreloc/} &&
OPTS="$OPTS $RPM_API $RPM_SELINUX --with-libintl-prefix=/usr"      &&
#persistent_add CPPFLAGS="$CPPFLAGS -I/usr/include/python$(installed_version python| cut -c 1-3)" &&
default_build
