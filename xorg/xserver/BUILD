#message CFLAGS=$CFLAGS
CFLAGS+=" -Wno-error=array-bounds" &&
OPTS+=" xorg=$XSERVER_XORG \
        xnest=$XSERVER_XNEST \
        xvfb=$XSERVER_XVFB \
        xselinux=${XSERVER_SELINUX} \
        xephyr=$XSERVER_XEPHYR \
        glamor=$XSERVER_GLAMOR \
        listen_tcp=$XSERVER_TCP \
        log_dir=${INSTALL_ROOT}/var/log \
        suid_wrapper=$XSERVER_WRAP \
        xkb_bin_dir=$INSTALL_ROOT/usr/bin" &&
PREFIX=/usr &&
default_build
