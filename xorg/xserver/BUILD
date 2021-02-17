#message CFLAGS=$CFLAGS
OPTS+=" xorg=$XSERVER_XORG \
        xwayland=false \
        xnest=$XSERVER_XNEST \
        xvfb=$XSERVER_XVFB \
        xselinux=${XSERVER_SELINUX} \
        xephyr=$XSERVER_XEPHYR \
        dmx=$XSERVER_DMX \
        glamor=$XSERVER_GLAMOR \
        listen_tcp=$XSERVER_TCP \
        log_dir=${INSTALL_ROOT}/var/log \
        xkb_bin_dir=$INSTALL_ROOT/usr/bin" &&
PREFIX=/usr &&
default_build
