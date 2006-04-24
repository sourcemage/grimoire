
patch  -p2  <  $SCRIPT_DIRECTORY/lilypond-2.2.6-syntax.patch	&&

# In case they weren't already used
mktextfm cmbxti8	&&
mktextfm cmbxti14	&&
mktextfm cmcsc7		&&
mktextfm cmcsc12	&&
mktextfm cmtt17		&&
mktextfm cmbx14		&&
mktextfm cmbx17		&&
mktextfm cmtt6		&&
mktextfm cmbxti5	&&
mktextfm cmti6		&&
mktextfm cmti5		&&
mktextfm cmss5		&&
mktextfm cmss6		&&
mktextfm cmss7		&&
mktextfm ecbm14		&&
mktextfm ecrm12		&&

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

