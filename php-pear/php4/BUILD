#
# Append options from CONFIGURE to OPTS
#
OPTS="$OPTS           \
      $PHP4_SAFE      \
      $PHP4_CALENDAR  \
      $PHP4_PCRE      \
      $PHP4_PCNTL     \
      $PHP4_FTP       \
      $PHP4_FCGI      \
"  &&

#
# Setup SSL IMAP if wanted
#
if  echo  $OPTS  |  grep  -q  --  --with-imap;  then
  if  spell_ok  openssl;  then
    OPTS="$OPTS  --with-imap-ssl"
  fi
fi  &&

case "$PHP4_APACHE" in
  handler)
    if  httpd  -v  |  grep  -q  "Apache/2\.";  then
      message  "${MESSAGE_COLOR}Configuring for Apache 2.x${DEFAULT_COLOR}"  &&
      OPTS="$OPTS  --with-apxs2"
      # fix the "missing APR include files" error
      #CFLAGS="$CFLAGS  -I/usr/include/apr"
    else
      message  "${MESSAGE_COLOR}Configuring for Apache 1.x${DEFAULT_COLOR}"  &&
      OPTS="$OPTS  --with-apxs"
    fi
    ;;
  filter)
    OPTS="$OPTS --with-apxs2filter"
    ;;
esac  &&

#Check for xorg or xserver and pass location of xpm
if [ "$PHP4_X11LIBS" == "y" ]; then
  OPTS="$OPTS --with-xpm-dir=/usr"
fi &&

#check to see if internal GD requested
if [ "$PHP4_GD" == "internal" ]; then
       OPTS="--with-gd --enable-gd-native-ttf $OPTS"
fi &&

./configure      --prefix=${INSTALL_ROOT}/usr      \
             --sysconfdir=${INSTALL_ROOT}/etc      \
          --with-exec-dir=${INSTALL_ROOT}/usr/bin  \
  --with-config-file-path=${INSTALL_ROOT}/etc      \
                 --enable-cli                      \
                --disable-static                   \
                --disable-debug                    \
                --disable-rpath                    \
          --enable-inline-optimization             \
                 --enable-pic                      \
                 --enable-bcmath                   \
           --enable-magic-quotes                   \
                 --enable-sysvsem                  \
                 --enable-sysvshm                  \
       --enable-force-cgi-redirect                 \
                 --enable-wddx                     \
                 --enable-filepro                  \
                 --enable-dbase                    \
                 --enable-sockets                  \
                   --with-iconv                    \
                   --with-xmlrpc                   \
                   --with-versioning               \
                   --with-mod_charset              \
                   --with-pear                     \
            --with-layout=GNU                      \
                          $OPTS                    &&
make                                               &&

# safety precaution against earlier PHP installations removing httpd.conf
pushd "$INSTALL_LOGS" &>/dev/null
local each
for each in $SPELL-*; do
  if test -f "$each"; then
    sedit 's|.*/httpd\.conf.*||g'  "$each" 
  fi
done
popd &>/dev/null
