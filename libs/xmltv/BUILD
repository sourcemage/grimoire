  local TV_OPT       &&
  TV_OPT=`echo $TV_GRAB $TV_CHECK $TV_CGI|sed "s/\t//"` &&
  yes | perl Makefile.PL PREFIX=$INSTALL_ROOT/usr \
          INSTALLDIRS=vendor                      \
          --components="$TV_OPT"        &&
  make                                  &&
  make test
