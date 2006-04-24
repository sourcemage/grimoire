# disable emacs, bug #8592
sedit  's/EMACS = @EMACS@/EMACS = no/'  gettext-tools/misc/Makefile.in  &&

export  CC=gcc  &&

make_single  &&

./configure  --build=$BUILD                           \
              --host=$HOST                            \
            --prefix=${TRACK_ROOT}/usr                \
        --sysconfdir=${TRACK_ROOT}/etc                \
           --infodir=${TRACK_ROOT}/usr/share/info     \
            --mandir=${TRACK_ROOT}/usr/share/man      \
             --with-included-gettext                  \
        --includedir=${TRACK_ROOT}/usr/local/include  \
             $OPTS                                    &&

make  &&

if  [  "$GETTEXT_TETEX"  ==  "y"  ];  then
  cd  gettext-tools/doc  &&
  make  dvi              &&
  make  ps               &&
  make  pdf              &&
  cd  -
fi  &&

make_normal  &&

#
# Remove libintl.h from old log files
#
(  sedit  '/libintl.h/d'  $INSTALL_LOGS/gettext*            ||  true  )  &&
(  sedit  '/libintl.h/d'  /var/log/sorcery/md5sum/gettext*  ||  true  )
