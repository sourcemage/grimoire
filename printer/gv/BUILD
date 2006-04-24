(

  cp  $SCRIPT_DIRECTORY/gv.man  doc
  cp  $SCRIPT_DIRECTORY/gv.man  source

# I'm not sure why this is here -- Jason
#  perl  -i  -pe  's/ComplexProgramTarget/ComplexProgramTargetNoMan/'  source/Imakefile  &&

  patch  -p1  <  $SCRIPT_DIRECTORY/asa-0000.gv-3.5.8.patch  &&
  patch  -p1  <  $SCRIPT_DIRECTORY/gv-3.5.8-debian.diff     &&
  xmkmf                                                     &&
  cd  source                                                &&
  ./inc_2lit                                                &&
  cd  -                                                     &&
  make  Makefiles                                           &&
  make                                                      &&
  prepare_install                                           &&
  make  GV_BINDIR=${INSTALL_ROOT}/usr/bin/                  \
        GV_DOCDIR=${INSTALL_ROOT}/usr/bin/                  \
        GV_LIBDIR=${INSTALL_ROOT}/usr/lib/gv/               \
        GV_MANDIR=${INSTALL_ROOT}/usr/man/man1/             \
        install                                             &&
  make  GV_BINDIR=${INSTALL_ROOT}/usr/bin/                  \
        GV_DOCDIR=${INSTALL_ROOT}/usr/bin/                  \
        GV_LIBDIR=${INSTALL_ROOT}/usr/lib/gv/               \
        GV_MANDIR=${INSTALL_ROOT}/usr/man/man1/             \
        install.man

) > $C_FIFO 2>&1
