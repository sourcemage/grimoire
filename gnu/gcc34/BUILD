# Doesn't know core2, replace with nocona, nor does it no -mssse3, remove it
# Doesn't know native -march nor -mtune (GCC 4.2+)
# Doesn't know -msse4* nor -msse5
# See http://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/i386-and-x86_002d64-Options.html
CFLAGS=${CFLAGS/core2/nocona}    &&
CXXFLAGS=${CFLAGS/core2/nocona}  &&
CFLAGS=${CFLAGS/-mssse3/}        &&
CXXFLAGS=${CXXFLAGS/-mssse3/}    &&
CFLAGS=${CFLAGS/-msse4a/}        &&
CXXFLAGS=${CXXFLAGS/-msse4a/}    &&
CFLAGS=${CFLAGS/-msse4.1/}       &&
CXXFLAGS=${CXXFLAGS/-msse4.1/}   &&
CFLAGS=${CFLAGS/-msse4.2/}       &&
CXXFLAGS=${CXXFLAGS/-msse4.2/}   &&
CFLAGS=${CFLAGS/-msse4/}         &&
CXXFLAGS=${CXXFLAGS/-msse4/}     &&
CFLAGS=${CFLAGS/-msse5/}         &&
CXXFLAGS=${CXXFLAGS/-msse5/}     &&

case $ARCHITECTURE in
  native-x86_64-64)
      CFLAGS=${CFLAGS/-march=native -mtune=native/-march=x86-64 -fPIC -DPIC}   &&
    CXXFLAGS=${CXXFLAGS/-march=native -mtune=native/-march=x86-64 -fPIC -DPIC}
    ;;
  native-x86_64-32)
      CFLAGS=${CFLAGS/-march=native -mtune=native/-march=i486 -m32} &&
    CXXFLAGS=${CXXFLAGS/-march=native -mtune=native/-march=i486 -m32}
    ;;
esac &&

cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                               \
             --host=$HOST                                 \
           --prefix=${INSTALL_ROOT}/opt/gcc34             \
          --infodir=${INSTALL_ROOT}/opt/gcc34/share/info  \
           --mandir=${INSTALL_ROOT}/opt/gcc34/share/man   \
   --enable-threads=posix                                 \
 --enable-languages=c,c++                                 \
       $GCC_MULTILIB $OPTS                                &&

make  profiledbootstrap
