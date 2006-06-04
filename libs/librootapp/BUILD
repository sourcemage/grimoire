sed -i 's:/usr/local:/usr:g' Init.make &&
# disable_pic will only disable it on non-x86_64 systems
# so these two lines effectively enable it only on x86_64 systems
CFLAGS="$CFLAGS -fPIC -DPIC" &&
disable_pic &&
make
