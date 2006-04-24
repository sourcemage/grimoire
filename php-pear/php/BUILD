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
    else
      message  "${MESSAGE_COLOR}Configuring for Apache 1.x${DEFAULT_COLOR}"  &&
      OPTS="$OPTS  --with-apxs"
    fi
    ;;
  filter)
    OPTS="$OPTS --with-apxs2filter"
    ;;
esac  &&

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
                 --enable-pdo                      \
            --with-layout=GNU                      \
                          $OPTS                    &&
invoke_gcc &&
make                                               &&

# safety precaution against earlier PHP installations removing httpd.conf
# we can remove this sedit after a couple of ISOs (today's 2003-11-05)
if  [  -f  $INSTALL_LOGS/$SPELL-*  ]
   then  sedit 's|.*/httpd\.conf.*||g'  $INSTALL_LOGS/$SPELL-* 
fi
