if [[ $TOR_USERGROUP == tor ]]; then
  create_account tor
fi &&

OPTS="--with-tor-user=$TOR_USERGROUP \
     --with-tor-group=$TOR_USERGROUP \
                      $TOR_OPTS \
                      $OPTS" &&

default_build
