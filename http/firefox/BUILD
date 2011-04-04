cd $SOURCE_DIRECTORY/mozilla* &&

FIREFOX_HOME="$INSTALL_ROOT/usr/lib/firefox" &&
export  MOZ_PHOENIX=1 &&


if [[ "$FIREFOX_CVS" == "y" ]]; then
  autoconf-2.13 || return 1
fi &&

echo ac_add_options --enable-application=browser >> .mozconfig &&
echo ac_add_options --disable-necko-wifi >> .mozconfig &&
echo ac_add_options --disable-mailnews >> .mozconfig &&
echo "ac_add_options --disable-updater" >> .mozconfig &&
echo ac_add_options --with-system-libxul --with-libxul-sdk=/usr/lib/xulrunner-1.9 >> .mozconfig &&
if [[ $FIREFOX_OFFICIAL == y ]]; then
  echo "ac_add_options --enable-official-branding" >> .mozconfig || return 1
fi &&

mozilla_build

