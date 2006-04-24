(

  ##########################################
  ##  Patching and initial configuration  ##
  ##########################################

  create_account phone                                          &&

  export MGETTY_CFLAGS=${CFLAGS}                                &&

  cp policy.h-dist policy.h                                     &&
  patch -p0 < $SCRIPT_DIRECTORY/Makefile.patch                  &&

  case $LOGIN_PATCH in
    y|Y|j|J)
      patch -p0 < $SCRIPT_DIRECTORY/policy.h.misc.patch
      ;;
    *)
      true
      ;;
  esac                                                          &&

  case $NEWFAX_PATCH in
    y|Y|j|J)
      patch -p0 < $SCRIPT_DIRECTORY/policy.h.new_fax.patch
      ;;
    *)
      true
      ;;
  esac                                                          &&

  ###################################
  ##  Build the selected packages  ##
  ###################################

  make                                                          &&

  if grep -q 'INCLUDE_CALLBACK="y"' ${SPELL_CONFIG}; then
     cd   callback/                                             &&
     patch -p0 < $SCRIPT_DIRECTORY/Makefile.callback.patch      &&
     make                                                       &&
     cd   ../
  fi                                                            &&

  if grep -q 'INCLUDE_DIALOG="y"' ${SPELL_CONFIG}; then
     cd   frontends/dialog/                                     &&
     patch -p0 < $SCRIPT_DIRECTORY/Makefile.dialog.patch        &&
     make                                                       &&
     cd   ../../
  fi                                                            &&

  if grep -q 'INCLUDE_VIEWFAX="y"' ${SPELL_CONFIG}; then
     cd   frontends/X11/viewfax-2.5/                            &&
     patch -p0 < $SCRIPT_DIRECTORY/Makefile.viewfax.patch       &&
     xmkmf                                                      &&
     make                                                       &&
     make depend                                                &&
     cd   ../../../
  fi                                                            &&

  if grep -q 'INCLUDE_TOOLS="y"' ${SPELL_CONFIG}; then
     cd   tools/                                                &&
     patch -p0 < $SCRIPT_DIRECTORY/Makefile.tools.patch         &&
     make                                                       &&
     cd   ../
  fi                                                            &&

  if grep -q 'INCLUDE_VGETTY="y"' ${SPELL_CONFIG}; then
     make vgetty
  fi                                                            &&

  #####################################
  ##  Install the selected packages  ##
  #####################################

  prepare_install                                               &&
  make    install                                               &&

  if grep -q 'INCLUDE_CALLBACK="y"' ${SPELL_CONFIG}; then
     cd   callback/                                             &&
     make install                                               &&
     cd   ../
  fi                                                            &&

  if grep -q 'INCLUDE_DIALOG="y"' ${SPELL_CONFIG}; then
     cd   frontends/dialog/                                     &&
     make install                                               &&
     cd   ../../
  fi                                                            &&

  if grep -q 'INCLUDE_TCLTK="y"' ${SPELL_CONFIG}; then
     cd   frontends/tcl/faxview-0.2/                            &&
     sedit "s:/usr/local/bin/wish:/usr/bin/wish:g" faxview.tcl  &&
     install -m 755 faxview.tcl /usr/bin/faxview                &&
     install -m 444 faxview.man /usr/man/man1/faxview.1         &&
     cd   ../../../
  fi                                                            &&

  if grep -q 'INCLUDE_VIEWFAX="y"' ${SPELL_CONFIG}; then
     cd   frontends/X11/viewfax-2.5/                            &&
     make install                                               &&
     make install.man                                           &&
     cd   ../../../
  fi                                                            &&

  if grep -q 'INCLUDE_SAMPLES="y"' ${SPELL_CONFIG}; then
     if ! [ -d /usr/share/mgetty ]; then
        mkdir -p /usr/share/mgetty/                             &&
        cp -r samples/ /usr/share/mgetty/
     fi
  fi                                                            &&

  if grep -q 'INCLUDE_TOOLS="y"' ${SPELL_CONFIG}; then
     cd   tools/                                                &&
     make install                                               &&
     cd   ../
  fi                                                            &&

  if grep -q 'INCLUDE_VGETTY="y"' ${SPELL_CONFIG}; then
     make vgetty-install
  fi                                                            &&

  ###########################
  ##  Final configuration  ##
  ###########################

  if [ -e /var/spool/fax ]; then
     chown -R phone.phone /var/spool/fax/                       &&
     chmod -R 770         /var/spool/fax/
  fi

) > $C_FIFO 2>&1
