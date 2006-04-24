real_sedit "s/\$(pkgdatadir)\/doc/\/usr\/share\/doc\/graphviz/" \
	doc/Makefile.am                                         &&

real_sedit "s/\$(pkgdatadir)\/doc/\/usr\/share\/doc\/graphviz/" \
	doc/info/Makefile.am                                    &&

aclocal -I config                                               &&
autoheader                                                      &&
libtoolize --force --copy                                       &&
aclocal                                                         &&
autoconf                                                        &&
automake --foreign --add-missing --copy                         &&

default_build
