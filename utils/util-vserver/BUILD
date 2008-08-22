local LOC_VSERV_API apis
if [[ ${VSERV_API/DEFAULT/} == ${VSERV_API} ]]
then
  for apis in $VSERV_API ; do
    LOC_VSERV_APIS="$LOC_VSERV_APIS,$apis"
  done
  LOC_VSERV_APIS="--enable-apis=$LOC_VSERV_APIS"
else
  LOC_VSERV_APIS=""
fi
OPTS="--with-initrddir=$INSTALL_ROOT/usr/share/doc/util-vserver/init   \
      --with-vrootdir=${INSTALL_ROOT}${VSERV_INSTALL}                  \
      $LOC_VSERV_APIS                                                  \
      $OPTS"                                                           &&
default_build
