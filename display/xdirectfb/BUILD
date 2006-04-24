
message  "Building xdirectfb takes a very long time."

( 
  rm -f config/cf/host.def                                                          &&

  if  (echo $CFLAGS | grep -q -- "-Os"); then
    export CFLAGS="-O2 ${CFLAGS//-Os/}"
  fi                                                                                &&

  if  spell_ok  linux-pam
  then  echo  "#define  HasPam  YES"  >>  config/cf/site.def
  fi                                                                                &&

  ### xdirectfb specific stuff
  cp $SOURCE_DIRECTORY/programs/Xserver/hw/xfree86/xf86Version.h $SOURCE_DIRECTORY/ &&
  cp $SOURCE_DIRECTORY/programs/Xserver/hw/xfree86/xf86Date.h $SOURCE_DIRECTORY/    &&
cat <<__EOF__ >config/cf/host.def

#define DefaultCCOptions      $CFLAGS
#define DefaultGcc2i386Opt    $CFLAGS
#define LibraryCDebugFlags    $CFLAGS
#define DefaultCDebugFlags    $CFLAGS
#define HasShm                  YES
#define HasZlib                 YES
#define HasFreetype2            YES
#define HasFontconfig           YES
#define BuildFreetype2Library   NO
#define HasExpat                YES
#define XDirectFBServer         YES
#define BuildScanpci            YES
#define BuildXF86VidModeLibrary YES
#define BuildXInputLib          YES
#define BuildXIE                YES
#define BuildXvLibrary          YES
#define BuildXvExt              YES
#define BuildXvMCLibrary        YES
#define BuildXvMCExt            YES
#define BuildXF86DGALibrary     YES
#define BuildGLXLibrary         YES
#define BuildGlxExt             YES
#define BuildXF86MiscLibrary    YES
#define BuildXextLib            YES
#define BuildGLULibrary         YES
#define BuildOSMesaLib          YES
#define BuildXprint             YES
__EOF__
  # end
 
  if echo $CFLAGS| grep -q "mmmx" 
  then echo "#define HasMMXSupport YES" >> config/cf/host.def
  fi      &&
  if echo $CFLAGS| grep -q "msse" 
  then echo "#define HasSSESupport YES" >> config/cf/host.def
  fi      &&
  if echo $CFLAGS| grep -q "m3dnow" 
  then echo "#define Has3DNowSupport YES" >> config/cf/host.def
  fi      &&

  cd config/util                                                 &&
  make -f Makefile.ini lndir                                     &&
  cp lndir $SOURCE_DIRECTORY.bld/                                &&
  cd $SOURCE_DIRECTORY.bld                                       &&
  ./lndir ../xc/                                                 &&
  ### Fix Bug #3486, which stops the build process
  ln -sf $SOURCE_DIRECTORY.bld/lib/font/builtins $SOURCE_DIRECTORY.bld/lib/font/builtins/unshared &&
  ### Some IMAKE issues from the XDirectFB patches need fixing
  # we are about to symlink some headers
  # normally  make World does a make clean too so the symlinks would get removed 
  #unless we do the following to the Imakefile
  sedit "s/\$(RM) -r \$(BUILDINCDIR)//" $SOURCE_DIRECTORY/Imakefile                                       &&
  # now make some dirs and the symlinks
  mkdir -p $SOURCE_DIRECTORY.bld/exports/include/X11/PM                                                   &&
  mkdir -p $SOURCE_DIRECTORY.bld/exports/include/X11/extensions                                           &&
  mkdir -p $SOURCE_DIRECTORY.bld/exports/include/X11/fonts                                                &&
  ln -sf $SOURCE_DIRECTORY/programs/proxymngr/PM* $SOURCE_DIRECTORY.bld/exports/include/X11/PM/           &&
  ln -sf $SOURCE_DIRECTORY/lib/font/include/fontenc.h $SOURCE_DIRECTORY.bld/exports/include/X11/fonts/    &&
  ln -sf $SOURCE_DIRECTORY/programs/xlsfonts/dsimple.h $SOURCE_DIRECTORY.bld/exports/include              &&
  sedit "s/hw\/i810//" $SOURCE_DIRECTORY.bld/lib/XvMC/Imakefile                                           &&
  sedit "s/INCLUDES = \$(KRB5_INCLUDE)/& \-I greeter\//" $SOURCE_DIRECTORY.bld/programs/xdm/Imakefile     &&

  make World

  ### Some more IMAKE issues from the XDirectFB patches need fixing
  man2html $SOURCE_DIRECTORY.bld/doc/man/Xext/XTransparency._man > $SOURCE_DIRECTORY.bld/doc/man/Xext/XTransparency.3x.html  &&
  ### Start compiling where the prior left off
  make                                                                                               &&
  prepare_install                                                                                    &&

  ### the following is needed for pkgconfig to find the .pc files
  mkdir  -p  ${INSTALL_ROOT}/usr/X11R6/lib                                                           &&
  ln -sf  ${INSTALL_ROOT}/usr/lib/pkgconfig  ${INSTALL_ROOT}/usr/X11R6/lib                           &&
  make  install                                                                                      &&
  ### more IMAKE foobars
  mkdir -p ${INSTALL_ROOT}/usr/X11R6/lib/X11/doc/html/                                               &&
  install -c -m 0444 $SOURCE_DIRECTORY.bld/doc/man/Xext/XTransparency.3x.html                        \
  ${INSTALL_ROOT}/usr/X11R6/lib/X11/doc/html/XTransparency.3.html                                    &&
  cp $SOURCE_DIRECTORY/config/cf/directfb.cf ${INSTALL_ROOT}/usr/X11R6/lib/X11/config/               &&
  cp $SOURCE_DIRECTORY/include/extensions/xf86vm* ${INSTALL_ROOT}/usr/X11R6/include/X11/extensions/  &&
  ### normal
  make  install.man                                                                                  &&
  mkdir  -p  /usr/X11R6/include/GL

) > $C_FIFO 2>&1  &&  (

  rm     -f  /usr/X11R6/include/zlib.h
  rm     -f  /usr/X11R6/lib/libz.a

  if  [  !  -e                      /etc/skel/.xsession  ];  then
    cp  $SCRIPT_DIRECTORY/xsession  /etc/skel/.xsession
  fi

  if  [  !  -e                    /usr/bin/X11  ];  then
    ln      -sf   /usr/X11R6/bin  /usr/bin/X11
  fi

  if  [  !  -e          /usr/X11  ];  then
    ln      -sf  X11R6  /usr/X11
  fi

  if  [  !  -e                         /usr/include/X11  ];  then
    ln      -sf  ../X11R6/include/X11  /usr/include/X11
  fi

  if  [  !  -e                     /usr/lib/X11  ];  then
    ln      -sf  ../X11R6/lib/X11  /usr/lib/X11
  fi

)


