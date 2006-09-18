echo "building for $COMPIZ_XTYPE" &&

if [ "$COMPIZ_XTYPE" == "xgl" ];  then
   OPTS="--with-gl-libs=/usr/lib/libGL-indirect/libGL.a $OPTS"
   LDFLAGS="$LDFLAGS -pthread -ldrm"
   # this avoids the need for the same hack on spells that depend on compiz
   sed -i 's|Libs: .*|\0 /usr/lib/libGL-indirect/libGL.a -pthread -ldrm|' compiz.pc.in
fi &&

default_build
