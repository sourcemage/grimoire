#!/bin/bash

# Let's not use the configure.sh bundled with this. It's no good for us.
# NOTE: This function needs changing when confug.in changes significantly.
# SUBNOTE: That isn't likely to happen.
my_configure() {
  local VARNAME DEFAULT VALUE
  while read VARNAME DEFAULT ;do
  # We should not be needing the default here, but well...
    VALUE=${!VARNAME}
    if [[ ${VALUE:-$DEFAULT} == y ]] ;then
      echo "#define $VARNAME 1" >&3
      echo "$VARNAME=1" >&4
    else
      echo "#define $VARNAME 0" >&3
      echo "$VARNAME=0" >&4
    fi
  done < <(sed -n "s/^bool '[^']*' //p" config.in) \
    3>config.h 4>config.make
  echo "configure script insane. We cheated." >config.status
}

echo  -e\n  $CONFIG_OPTS  >  smgl_config_opts                &&
patch  -p1  <  $SCRIPT_DIRECTORY/gcc-3.4.patch               &&
patch  -p1  <  $SCRIPT_DIRECTORY/x25_address-fix.patch       &&
patch  -p1  <  $SCRIPT_DIRECTORY/double-free-nameif.patch    &&
sedit  '382,391s/$/\\n\\/'  mii-tool.c                       &&
my_configure                                                 &&
make_single                                                  &&
make  COPTS="-D_GNU_SOURCE -Wall $CFLAGS"  LOPTS="$LDFLAGS"


