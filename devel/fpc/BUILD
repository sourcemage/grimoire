if    [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "ia32"    ]];  then
  ARCH=386  # Yes, they switch between i386 and 386...
elif  [[  "${SMGL_COMPAT_ARCHS[1]}"  ==  "x86_64"  ]];  then
  ARCH=x64  # Yes, they switch between x86_64 and x64...
else
  ARCH=386
fi  &&

if ! spell_ok fpc ; then
#
# First compile a local version with the bootstrap
#
make PP=$SOURCE_DIRECTORY/bootstrap/lib/fpc/$VERSION/ppc$ARCH compiler_cycle  &&
cp $SOURCE_DIRECTORY/compiler/ppc$ARCH         \
   $SOURCE_DIRECTORY/bootstrap/ppc$ARCH.local  &&

#
# Now recompile our new bootstrap with our local compiler
#
make PP=$SOURCE_DIRECTORY/bootstrap/ppc$ARCH.local compiler_cycle  &&
rm -f $SOURCE_DIRECTORY/bootstrap/ppc$ARCH.local                   &&
#
# Build all with our newly forged local FPC
#
  PP=$SOURCE_DIRECTORY/compiler/ppc$ARCH
else
# use installed fpc
  PP=$INSTALL_ROOT/usr/bin/fpc
fi &&
make PP=$PP build      
