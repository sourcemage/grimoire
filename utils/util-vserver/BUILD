local VSERV_API apis
for apis in $VSERV_API ; do
  if [[ "$apis" == "DEFAULT" ]]; then
    VSERV_APIS="$VSERV_APIS,v13,net,v21"
  fi
  VSERV_APIS="$VSERV_APIS,$apis"
done
OPTS="--with-initrddir=$INSTALL_ROOT/usr/share/doc/util-vserver/init   \
      --with-vrootdir=${INSTALL_ROOT}${VSERV_INSTALL}                  \
      --enable-apis=$VSERV_APIS                                        \
      $OPTS"                                                           &&
default_build
