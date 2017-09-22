
if  is_depends_enabled  $SPELL  gettext
then
  CONFIG_OPTS="y\n\
$CONFIG_OPTS"
else
  CONFIG_OPTS="n\n\
$CONFIG_OPTS"
fi  &&

echo  -e\n  $CONFIG_OPTS  >  smgl_config_opts                &&
sedit  '382,391s/$/\\n\\/'  mii-tool.c                       &&
./configure.sh  config.in  <  smgl_config_opts               &&
make_single                                                  &&
make  COPTS="-D_GNU_SOURCE -Wall $CFLAGS"  LOPTS="$LDFLAGS"
