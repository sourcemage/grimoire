if  !  [  -e  $TRACK_ROOT/usr/bin/g77  ];  then
  OPTS="$OPTS  --without-fc"
fi  &&

./configure      --prefix=$INSTALL_ROOT/usr      \
             --sysconfdir=$INSTALL_ROOT/etc/lam  \
                          $OPTS                  &&

make
