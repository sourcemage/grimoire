if [ "$LOCKING" == "y" ]; then
   OPTS="$OPTS --enable-locking"
else
   OPTS="$OPTS --disable-locking"
fi                                        &&

make_single                               &&
default_build                             &&
make_normal

