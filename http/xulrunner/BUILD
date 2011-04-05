cd "$SOURCE_DIRECTORY/mozilla-2.0" &&

XULRUNNER_HOME="$INSTALL_ROOT/usr/lib/xulrunner" &&
export  MOZ_PHOENIX=1 &&

#echo "ac_add_options --with-system-libevent" >> .mozconfig             &&
echo "ac_add_options --disable-javaxpcom" >> .mozconfig &&
echo "ac_add_options --disable-mochitest" >> .mozconfig &&
echo "ac_add_options --enable-jemalloc" >> .mozconfig &&
echo "ac_add_options --enable-jsd" >> .mozconfig &&
echo "ac_add_options --enable-libnotify" >> .mozconfig        &&


mozilla_build
