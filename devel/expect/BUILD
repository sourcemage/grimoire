if echo $OPT | grep -q tk; then
   export LDFLAGS="$LDFLAGS -L /usr/X11R6/lib" 
fi                                 &&

cd  $SOURCE_DIRECTORY/             &&
./configure  --prefix=/usr \
             --with-tcl=/usr/lib \
             $OPTS                 &&
make_single                        &&
make
