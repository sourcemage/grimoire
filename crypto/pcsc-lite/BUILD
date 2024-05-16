LDFLAGS+=" -ldl" &&
if  is_depends_enabled $SPELL systemd;then
  OPTS+=' libsystemd=true'
fi &&
for DD in $PCSC_DEVICES;do
  OPTS+=" $DD=true"
done &&

default_build
