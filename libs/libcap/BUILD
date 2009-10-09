# fails to compile on non amd64 with PIC, bug #9087
disable_pic  &&

# -I added (bug #14583)
# -L added (bug #14660)
make PAM_CAP=$LIBCAP_PAM CFLAGS="$CFLAGS -I$SOURCE_DIRECTORY/libcap/include -L$SOURCE_DIRECTORY/libcap"
