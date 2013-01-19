export  CC=gcc  &&

# pth support is semi-broken, so force POSIX threads
OPTS="--enable-threads=posix $OPTS" &&

# never rely on external glib2
OPTS="--with-included-glib $OPTS" &&
# use this version of getext
OPTS+=" --with-included-gettext" &&

default_build &&

if  is_depends_enabled $SPELL tetex;  then
  cd  gettext-tools/doc  &&
  make  dvi              &&
  make  ps               &&
  make  pdf              &&
  cd  -
fi  &&

#
# Remove libintl.h from old log files
#
(  sedit  '/libintl.h/d'  $INSTALL_LOGS/gettext*            ||  true  )  &&
(  sedit  '/libintl.h/d'  /var/log/sorcery/md5sum/gettext*  ||  true  )
