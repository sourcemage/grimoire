# Force a specific C standard to avoid build failures with newer compilers
case "$(${CC-gcc} --help)" in
  (*\ -std=*) CFLAGS+=' -std=c17';;
esac &&

OPTS+=" --build=${BUILD}" &&
if [[ $CROSS_INSTALL == on ]]; then
  OPTS+=" --host=${HOST}"
fi &&

  ./configure --prefix=${TRACK_ROOT}/usr  \
          --sysconfdir=${TRACK_ROOT}/etc  \
              --bindir=${TRACK_ROOT}/bin  \
       --localstatedir=${TRACK_ROOT}/var  \
              --mandir=${TRACK_ROOT}/usr/share/man   \
             --infodir=${TRACK_ROOT}/usr/share/info  \
                       $OPTS                 &&
  make DESTDIR=$INSTALL_ROOT

