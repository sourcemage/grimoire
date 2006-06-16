OPTS="$KDE_DEBUG_OPTION                  \
      $KDE_FINAL_OPTION                  \
      $KDE_LDFLAGS                       \
      --enable-dnotify                   \
      --with-distribution                \
      --disable-dependency-tracking      \
      $OPTS"                             &&

if [[ -f /etc/profile.d/qt.sh ]]; then
  . /etc/profile.d/qt.sh
fi                                       &&

#default_build

#  debug "build_api/api2" "real_default_build"

  OPTS="$OPTS --build=${BUILD}"
  #If these switches are used, they _may_ stop distcc and ccache from work$
  # for some spells (bug 3798)
  #  We could write wrappers for all of the possible binaries
  [[ $CROSS_INSTALL == on ]] && OPTS="$OPTS --host=${HOST}"

  ./configure --prefix=${INSTALL_ROOT}/usr  \
          --sysconfdir=${INSTALL_ROOT}/etc  \
       --localstatedir=${INSTALL_ROOT}/var  \
              --mandir=${INSTALL_ROOT}/usr/share/man   \
             --infodir=${INSTALL_ROOT}/usr/share/info  \
                       $OPTS                 &&

patch  -p0  <  $SCRIPT_DIRECTORY/Makefile.patch       &&
patch  -p0  <  $SCRIPT_DIRECTORY/Makefile-f4lm.patch  &&

  make

#source $SECTION_DIRECTORY/KDE_BUILD
