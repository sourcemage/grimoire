OPTS="--enable-shared $OPTS" &&
#patch -p0 < $SPELL_DIRECTORY/bk.diff &&
#bakefile -f autoconf flamerobin.bkl  &&
mkdir release       &&
cd release          &&
ln -s ../configure  &&
export IBPP=/usr    &&
default_build
