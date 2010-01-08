export CHROMIUM_HOME=$INSTALL_ROOT/usr/lib/chromium-browser &&

OPTS="-Dlinux_sandbox_path=$CHROMIUM_HOME/chrome_sandbox \
      -Dlinux_sandbox_chrome_path=$CHROMIUM_HOME/chrome \
      $OPTS" &&

if [[  "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" ]]
then
  OPTS="-Dtarget_arch=x64 $OPTS"
else
  OPTS="-Dtarget_arch=ia32 $OPTS"
fi &&

local GCC_VER=$(installed_version gcc) &&
if [[ "${GCC_VER:0:3}" == "4.4" ]]
then
  OPTS="-Dno_strict_aliasing=1 \
        -Dgcc_version=44 \
        $OPTS"
fi &&

build/gyp_chromium -f make build/all.gyp $OPTS --depth=. &&

make -r V=1 \
     chrome \
     chrome_sandbox \
     BUILDTYPE=release \
     rootdir=$SOURCE_DIRECTORY
