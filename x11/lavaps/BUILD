if  [  "$LAVAPS_GTK"  ==  "y"  ];  then
  OPTS="$OPTS  --with-gtk"
else
  local  TCL_VERSION=`installed_version  tcl  |  cut  -c  1-3`  &&
  local  TK_VERSION=`installed_version  tk  |  cut  -c  1-3`    &&
  OPTS="$OPTS  --with-tcltk                      \
               --with-tcltk-lib-suffix-type=dot  \
               --with-tcl-ver=${TCL_VERSION}     \
               --with-tk-ver=${TK_VERSION}"
fi  &&

./configure  --prefix=/usr                     \
             --disable-schemas-install         \
             $OPTS                             &&

make
