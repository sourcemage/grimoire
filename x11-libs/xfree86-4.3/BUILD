install_drm()  {

  DRM_DIR="programs/Xserver/hw/xfree86/os-support/linux/drm/kernel"
  DRM_DEST="/lib/modules/$(uname -r)/kernel/drivers/char/drm"
  mkdir   -p                $DRM_DEST
  cp          $DRM_DIR/*.o  $DRM_DEST  2>/dev/null
  depmod  -a
  true

}


if    [  -f  $CONFIG_CACHE/host.def  ]
then  cp     $CONFIG_CACHE/host.def  config/cf/host.def
fi                                                      &&
### but if it can't be copied then use system defaults for these
if ! grep -q HasFreetype2 config/cf/host.def
    then echo "#define HasFreetype2   YES" >> config/cf/host.def
fi                                                      &&
if ! grep -q BuildFreetype2Library  config/cf/host.def
   then echo "#define BuildFreetype2Library     NO" >> config/cf/host.def
fi                                                      &&
if ! grep -q HasZlib config/cf/host.def
   then echo "#define HasZlib   YES" >> config/cf/host.def
fi                                                      &&
if ! grep -q HasFontconfig config/cf/host.def
   then echo "#define HasFontconfig  YES" >> config/cf/host.def
fi                                                      &&
if ! grep -q HasExpat config/cf/host.def
   then echo "#define HasExpat  YES" >> config/cf/host.def
fi                                                      &&
message  "Building XFree86 takes a very long time."

( 
  
  ### Apply 4.3.0.1 patch
  zcat  ${SOURCE_CACHE}/${SOURCE8}  |  patch  -p1  &&

  ### Apply Xinput locking patch
  patch  -p2  <  $SCRIPT_DIRECTORY/Xi-locking.patch  &&
  ### Apply linux version patch to support 2.6.X
  patch  -p1  <  $SCRIPT_DIRECTORY/XFree86-4.3.0-linux-2.6.0.patch  &&

  ### removing -Os from copied host.def bug#3694 and cleaning up $CFLAGS
  if [ -f config/cf/host.def ] 
  then sedit s"/-Os//g" config/cf/host.def 
  fi                                               &&
  if  (echo $CFLAGS | grep -q -- "-Os"); then
    export CFLAGS="-O2 ${CFLAGS//-Os/}"
  fi                                               &&

  if  spell_ok  linux-pam
  then  echo  "#define  HasPam  YES"  >>  config/cf/site.def
  fi                                               &&
  ### xfree86.org recommends building in a shadow tree 
  cd config/util                                   &&
  make -f Makefile.ini lndir                       &&
  cp lndir $SOURCE_DIRECTORY.bld/                  &&
  cd $SOURCE_DIRECTORY.bld                         &&
  ./lndir ../xc/                                   &&
  ### differnet approach to old bug
  ### Fix Bug #3486, which stops the build process if builtinfonts is selected
  ln -sf $SOURCE_DIRECTORY.bld/lib/font/builtins $SOURCE_DIRECTORY.bld/lib/font/builtins/unshared &&

  make World
  
  ### will this fix the mysterious error ?
  ln -sf $SOURCE_DIRECTORY/lib/xtrans/Xtrans.h  $SOURCE_DIRECTORY.bld/exports/include/X11/Xtrans.h &&
  ### Start compiling where the prior left off
  make                                                           &&
  prepare_install                                                &&
  #### the following is needed for pkgconfig to find the .pc files
  mkdir  -p  /usr/X11R6/lib                                      &&
  ln -sf  /usr/lib/pkgconfig  /usr/X11R6/lib                     &&
  make  install                                                  &&
  make  install.man                                              &&
        install_drm                                              &&
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
