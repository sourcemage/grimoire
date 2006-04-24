cd $SOURCE_DIRECTORY &&
#PERLVERSION=installed_version perl &&
#echo "Perl Version = ${PERLVERSION}" &&
sedit "s:BINDIR = /usr/local/bin:BINDIR = /usr/bin:" Makefile &&
sedit "s:PERL5DIR = /usr/local/lib/perl5:PERL5DIR = /usr/lib/perl5/$(installed_version perl):" Makefile  &&
make_single
