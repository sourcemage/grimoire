if [ "$MOD_PERL_2" == "y" ]; then
  OPTIONS="MP_APXS=$(which apxs) MP_APR_CONFIG=$(which apr-config)"
fi &&
make_single                              &&
perl  Makefile.PL  NO_HTTPD=1  $OPTIONS  &&
make                                     &&
make_normal
