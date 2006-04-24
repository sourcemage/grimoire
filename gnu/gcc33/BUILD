# fix bug #7205
sedit  's:#!/bin/sh:#!/bin/bash:'  $SOURCE_DIRECTORY/configure  &&

# GCC 3.3 doesn't know arch=pentium4m, replace with pentium4,
# same for pentium3m
CFLAGS=${CFLAGS/pentium4m/pentium4}      &&
CXXFLAGS=${CXXFLAGS/pentium4m/pentium4}  &&
CFLAGS=${CFLAGS/pentium-m/pentium3}      &&
CXXFLAGS=${CFLAGS/pentium-m/pentium3}    &&

cd $SOURCE_DIRECTORY.bld                                  &&
$SOURCE_DIRECTORY/configure                               \
             --host=$HOST                                 \
           --prefix=${INSTALL_ROOT}/opt/gcc33             \
          --infodir=${INSTALL_ROOT}/opt/gcc33/share/info  \
           --mandir=${INSTALL_ROOT}/opt/gcc33/share/man   \
   --enable-threads=posix                                 \
 --enable-languages=c,c++                                 \
       $GCC_MULTILIB $OPTS                                &&

# GCC 3.3 supports AMD64 as "-march=athlon-xp -m64", unlike "-march=k8 -m64" in 3.4.
# Variables *_FOR_TARGET are used to compile libraries after compiler itself is ready,
# therefore changing them will not influence the compiler build.
sedit 's|\(CFLAGS_FOR_TARGET.*\)\$(CFLAGS)|\1$(CFLAGS:k8=athlon-xp)|g' Makefile &&
sedit 's|\(CXXFLAGS_FOR_TARGET.*\)\$(CXXFLAGS)|\1$(CXXFLAGS:k8=athlon-xp)|g' Makefile &&
sedit 's|march=k8|march=athlon-xp|g' libiberty/Makefile libiberty/testsuite/Makefile &&

make  bootstrap
