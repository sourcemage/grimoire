create_account ntp &&

OPTS="--with-privsep-user=ntp \
      $OPTS" &&

# Needed for GCC 10.x+
CFLAGS+=" -fcommon" &&
default_build
