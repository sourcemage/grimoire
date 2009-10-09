cd $SOURCE_DIRECTORY &&
sed -i -e "s,/usr/local/lib/httpd,$XSHTTPD_ROOTDIR," config/httpd.conf.sample &&
sed -i -e 's,/usr/local,/usr,' config/script.methods.sample &&

if [[ $XSHTTPD_USE_PREFIX == "y" ]]; then
  sed -i -e 's/httpd.conf/xs&/' -e 's/httpd.pid/xs&/' config/httpd.conf.sample &&
  case $XSHTTPD_BRANCH in
    devel)
      sed -i -e 's/httpd.conf/xs&/' -e 's/httpd.pid/xs&/' src/constants.h
    ;;
    *)
      sed -i -e 's/httpd.conf/xs&/' -e 's/httpd.pid/xs&/' src/confuser.h
    ;;
  esac
  sed -i -e 's/^httpd/xs&/' -e 's/\([[:blank:]]\)\(httpd\)/\1xs\2/' -e 's/HTTPD/XS&/' man/*.{1,5,7}* &&
  sed -i -e 's/httpd.conf/xs&/' config/Makefile.* &&
  mv config/httpd.conf.sample config/xshttpd.conf.sample
fi &&

OPTS="$XSHTTPD_OPTS $OPTS" &&
default_build
