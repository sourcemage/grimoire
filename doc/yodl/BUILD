CFLAGS="$CFLAGS -c"                &&
perl contrib/build.pl make         &&
cd scripts                         &&
./configreplacements ../src/config.h yodl2whatever.in yodl2whatever &&
chmod +x yodl2whatever             &&
ln -s yodl2whatever yodl2html      &&
ln -s yodl2whatever yodl2latex     &&
ln -s yodl2whatever yodl2man       &&
ln -s yodl2whatever yodl2txt       &&
ln -s yodl2whatever yodl2xml

