# fails to compile on non amd64 with PIC, bug #9087
disable_pic  &&

# -I added (bug #14583)
make PAM_CAP=$LIBCAP_PAM CFLAGS="$CFLAGS -I$SOURCE_DIRECTORY/libcap/include"
