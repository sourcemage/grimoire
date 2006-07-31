./configure                                     &&

# these did not build 29.7.06
sed -ri "s/ecbx12|ecrm12|ecrm17|eccc12|ecrb12|ecrb14|ecrb17|ecss10|ecb12//g" GNUmakefile

# to generate tfm fonts to $SOURCE_DIRECTORY/output
# instead of /var/tmp/texfonts
patch -p 0 < $SCRIPT_DIRECTORY/makefile.patch   &&
builddir=$SOURCE_DIRECTORY make -e all
