sed -i '7326 s,num=`,ver='$(installed_version guile)'\n&,' configure &&
./configure  --build=$BUILD        \
             --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
--with-ncsb-dir=/usr/share/ghostscript/fonts \
             $OPTS                 &&


make all			   &&

if [ $HTMLDOC == y ]
then
	make web
fi

# sh ./buildscripts/clean-fonts.sh

