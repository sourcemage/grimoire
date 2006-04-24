(
  if `httpd -v | grep -q "Apache/2\."`; then
    message "${MESSAGE_COLOR}Configuring for Apache 2.x${DEFAULT_COLOR}" &&
    OPTS="$OPTS --with-apxs2"
  else
    message "${MESSAGE_COLOR}Configuring for Apache 1.x${DEFAULT_COLOR}" &&
    OPTS="$OPTS --with-apxs"
  fi &&

  if [ "$php_SAFEMODE" == "y" ]; then
    OPTS="$OPTS --enable-safe-mode"
  fi &&

  ./buildconf                          &&
  ./configure                          \
    --prefix=/usr                      \
    --sysconfdir=/etc                  \
    --with-exec-dir=/usr/bin           \
    --with-config-file-path=/etc       \
    --enable-cli                       \
    --disable-static                   \
    --disable-debug                    \
    --disable-rpath                    \
    --enable-inline-optimization       \
    --enable-pic                       \
    --enable-bcmath                    \
    --enable-magic-quotes              \
    --enable-sysvsem                   \
    --enable-sysvshm                   \
    --enable-force-cgi-redirect        \
    --enable-yp                        \
    --enable-ftp                       \
    --enable-wddx                      \
    --enable-filepro                   \
    --enable-dbase                     \
    --enable-sockets                   \
    --enable-calendar                  \
    --with-iconv-dir=/usr              \
    --with-xmlrpc                      \
    --with-regex=system                \
    --with-versioning                  \
    --with-mod_charset                 \
    --with-pear                        \
    --with-layout=GNU                  \
    --with-zlib                        \
    --with-x-includes=/usr/X11/include \
    --with-x-libraries=/usr/X11/lib    \
    $OPTS                              &&
  make                                 &&
  prepare_install                      &&
  make    install                      &&
  if         ! [ -e /etc/php.ini ]; then
    cp php.ini-dist /etc/php.ini
  fi

) > $C_FIFO 2>&1
