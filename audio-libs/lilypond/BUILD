sed -i '7326 s,num=`,ver='$(installed_version guile)'\n&,' configure &&
OPTS="$OPTS --with-ncsb-dir=/usr/share/ghostscript/fonts" &&
default_build &&

if [ $HTMLDOC == y ]
then
	make web
fi

# sh ./buildscripts/clean-fonts.sh

