./configure                                     &&

# to generate tfm fonts to $SOURCE_DIRECTORY/output
# instead of /var/tmp/texfonts
patch -p 0 < $SCRIPT_DIRECTORY/makefile.patch   &&
builddir=$SOURCE_DIRECTORY make -e all
