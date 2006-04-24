if [ "$CPDF" == "y" ]; then
   OPTS="$OPTS --enable-pdf"
fi                            &&

if [ "$CPS" == "y" ]; then
   OPTS="$OPTS --enable-ps"
fi                            &&

CFLAGS="${CFLAGS/-O3/-O2}"    &&	
default_build
