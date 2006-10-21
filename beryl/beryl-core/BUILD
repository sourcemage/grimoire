echo "building for $BERYL_XTYPE" &&

if [ "$BERYL_XTYPE" == "xgl" ];  then
   OPTS="--with-gl-libs=/usr/lib/libGL-indirect/libGL.a $OPTS"
   LDFLAGS="$LDFLAGS -pthread -ldrm"
   # this avoids the need for the same hack on spells that depend on beryl-core
   sed -i 's|Libs: .*|\0 /usr/lib/libGL-indirect/libGL.a -pthread -ldrm|' beryl.pc.in
fi &&

default_build
