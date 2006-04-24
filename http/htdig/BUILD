(

  CONFIG=/etc/htdig
  HTDIGDIR=/usr/share/htdig/htdocs
  CGIBINDIR=/usr/share/htdig/cgi-bin
  SEARCHFORM=search.html
  WEBPREFIX=/htdig
  DATABASE=/var/lib/htdig

  ./configure \
    --prefix=/usr \
    --sysconfdir=/etc \
    --with-config-dir=$CONFIG \
    --with-default-config-file=$CONFIG/htdig.conf \
    --with-database-dir=$DATABASE \
    --with-common-dir=$HTDIGDIR/common \
    --with-cgi-bin-dir=$CGIBINDIR \
    --with-image-dir=$HTDIGDIR \
    --with-search-dir=$HTDIGDIR \
    --with-image-url-prefix=$WEBPREFIX \
    --with-search-form=$SEARCHFORM \
    $OPTS &&
  make &&
  prepare_install &&
  make    install                 

) >$C_FIFO 2>&1
