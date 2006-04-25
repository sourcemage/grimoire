./configure  --prefix=$TRACK_ROOT/usr               \
            --datadir=$TRACK_ROOT/usr/share/$SPELL  \
             --mandir=$TRACK_ROOT/usr/share/man     &&

if  echo  $OPTS  |  grep  -q  --  "--without-nls";  then
  sedit  's:#define ENABLE_NLS::'  defines.h
fi  &&

make DESTDIR=$INSTALL_ROOT
