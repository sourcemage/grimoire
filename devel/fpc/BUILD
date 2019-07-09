if    [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "ia32"    ]];  then
  ARCH=386  # Yes, they switch between i386 and 386...
elif  [[  "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]];  then
  ARCH=x64  # Yes, they switch between x86_64 and x64...
else
  ARCH=386
fi  &&

if ! spell_ok fpc ; then
  PP=$SOURCE_DIRECTORY/bootstrap/lib/fpc/$VERSION/ppc$ARCH
else
  PP=$INSTALL_ROOT/usr/bin/fpc
fi &&
make PP=$PP build
