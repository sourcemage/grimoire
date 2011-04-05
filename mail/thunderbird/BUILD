cd  $SOURCE_DIRECTORY/comm-1.9.2  &&

THUNDERBIRD_HOME=${INSTALL_ROOT}/usr/lib/thunderbird &&
export  MOZ_THUNDERBIRD="1"   &&


if [[ $THUNDERBIRD_OFFICIAL == y ]]; then
  echo ac_add_options --enable-official-branding >> .mozconfig || return 1
fi
echo ac_add_options --with-user-appdir=.thunderbird >> .mozconfig &&
echo ac_add_options --enable-application=mail >> .mozconfig &&
echo ac_add_options --enable-static >> .mozconfig &&

mozilla_build
