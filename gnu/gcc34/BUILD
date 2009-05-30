# Doesn't know core2, replace with nocona, nor does it no -mssse3, remove it
# See http://gcc.gnu.org/onlinedocs/gcc-3.4.6/gcc/i386-and-x86_002d64-Options.html
CFLAGS=${CFLAGS/core2/nocona}    &&
CXXFLAGS=${CFLAGS/core2/nocona}  &&
CFLAGS=${CFLAGS/-mssse3/}        &&
CXXFLAGS=${CXXFLAGS/-mssse3/}    &&

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
