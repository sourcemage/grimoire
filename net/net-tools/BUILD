echo  -e\n  $CONFIG_OPTS  >  smgl_config_opts                &&
patch  -p1  <  $SCRIPT_DIRECTORY/gcc-3.4.patch               &&
patch  -p1  <  $SCRIPT_DIRECTORY/x25_address-fix.patch       &&
sedit  '382,391s/$/\\n\\/'  mii-tool.c                       &&
./configure.sh  config.in  <  smgl_config_opts               &&
make  COPTS="-D_GNU_SOURCE -Wall $CFLAGS"  LOPTS="$LDFLAGS"

