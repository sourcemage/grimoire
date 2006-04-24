./configure  --build=$BUILD        \
             --prefix=/usr         \
             --sysconfdir=/etc     \
             --localstatedir=/var  \
             $OPTS                 &&


make all			   &&

if [ $HTMLDOC == y ]
then
	make web
fi

# sh ./buildscripts/clean-fonts.sh

