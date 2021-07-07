export  CC=gcc  &&

# pth support is semi-broken, so force POSIX threads
OPTS="--enable-threads=posix $OPTS" &&

# never rely on external glib2
OPTS="--with-included-glib $OPTS" &&

./configure  --build=$BUILD                           \
              --host=$HOST                            \
            --prefix=${TRACK_ROOT}/usr                \
        --sysconfdir=${TRACK_ROOT}/etc                \
           --infodir=${TRACK_ROOT}/usr/share/info     \
            --mandir=${TRACK_ROOT}/usr/share/man      \
        --includedir=${TRACK_ROOT}/usr/local/include  \
             $OPTS                                    &&

make  &&

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
