OPTS="--build=$BUILD \
      $OPTS" &&

if [[ $CROSS_INSTALL == on ]]; then
  OPTS="--host=$HOST $OPTS"
fi &&

OPTS="--disable-eject \
      --disable-kill \
      --disable-last \
      --disable-login \
      --disable-mesg \
      --disable-nologin \
      --disable-su \
      --disable-sulogin \
      --disable-utmpdump \
      $OPTS"

create_group tty &&

disable_pic  &&

./configure --prefix=${TRACK_ROOT}/usr  \
        --sysconfdir=${TRACK_ROOT}/etc  \
     --localstatedir=${TRACK_ROOT}/var  \
            --mandir=${TRACK_ROOT}/usr/share/man   \
           --infodir=${TRACK_ROOT}/usr/share/info  \
                     $OPTS &&
default_build_make
