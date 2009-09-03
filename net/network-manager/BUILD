OPTS=" $OPTS --with-distro=debian"
for i in $(find -name Makefile.in); do
  sedit 's/-DGNOME_DISABLE_DEPRECATED//' $i
done 
default_build
