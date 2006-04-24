#./configure  --host=$HOST --build=$BUILD             \
#             --prefix=$INSTALL_ROOT/usr              \
#             --sysconfdir=$INSTALL_ROOT/etc          \
#             --localstatedir=$INSTALL_ROOT/var       \
#             --mandir=$INSTALL_ROOT/usr/share/man    \
#             --infodir=$INSTALL_ROOT/usr/share/info  \
#             $OPTS                                   &&
#
#make                                                 &&

default_build &&

if  [[ "$GS_LIBGS" == y  ]];  then
  make  so
fi
