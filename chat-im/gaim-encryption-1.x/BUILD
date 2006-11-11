### had to cook up some pkg-config files for nss and nspr 
if spell_ok nss ; then
  export PKG_CONFIG_PATH="/usr/include/nss:/usr/include/nspr" 
fi                                              &&
make_single    &&
OPTS="--with-nspr-includes=/usr/include/nspr --with-nspr-libs=/usr/lib $OPTS" &&
OPTS="--with-nss-includes=/usr/include/nss --with-nss-libs=/usr/lib $OPTS" &&
default_build  &&
make_normal
