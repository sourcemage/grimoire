# This is required for xfree86 4.4.0 and above, I haven't tested 4.3.99 or Xorg
if  gaze installed xfree86|grep -c -q 4.4;  then
  sed  "s/\#define NeedFunctionPrototypes 0/\/\*\#define NeedFunctionPrototypes 0\*\//" ${SOURCE_DIRECTORY}/src/modules/X11/dataentry.c > /tmp/dataentry.c &&
  mv /tmp/dataentry.c ${SOURCE_DIRECTORY}/src/modules/X11/
fi &&

export FPICFLAGS="-fPIC" &&
# Sergey change : export F77=$(which gfortran) &&
export F77=g77 &&
OPTS="--enable-linux-fs  \
      --enable-R-shlib   \
      $R_UTF8            \
      $OPTS"             &&

default_build
