if  echo  $OPTS  |  grep  -q  enable-pam;  then
  MAKEFLAG='CPPFLAGS=-DUSE_PAM su_LDFLAGS=-lpam_misc'         
fi  &&

./configure                                  \
   --build=$BUILD                            \
   --bindir=${TRACK_ROOT}/bin              \
   --prefix=${TRACK_ROOT}/usr              \
   --mandir=${TRACK_ROOT}/usr/share/man    \
   --infodir=${TRACK_ROOT}/usr/share/info  \
   $OPTS                                     &&

make  $MAKEFLAG DESTDIR=$INSTALL_ROOT
