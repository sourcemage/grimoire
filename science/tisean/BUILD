cd $SOURCE_DIRECTORY &&
# no fancy cross compilation...
FC=gfortran FFLAGS="$CFLAGS" ./configure --prefix="$SOURCE_DIRECTORY/.installbins" &&
make &&
echo "doing the local make install (needs a moment)" &&
make install &> /dev/null
