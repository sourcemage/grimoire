# Installs both dynamic and static binaries.
#OPTS="$OPTS --enable-static-cryptsetup" &&
# Kindof a hotfix: Open question if rather libgcrypt or libgpg-error should
# pull in libpthread. Really not sure, as it's not always needed.
# Or is it a gcc issue?
# /usr/src/gcc-4.9.2.bld/x86_64-pc-linux-gnu/libgcc/./gthr-default.h:778: undefined reference to `pthread_mutex_unlock'
# /usr/lib/gcc/x86_64-pc-linux-gnu/4.9.2/libgcc_eh.a(unwind-dw2-fde-dip.o):/usr/src/gcc-4.9.2.bld/x86_64-pc-linux-gnu/libgcc/./gthr-default.h:778: more undefined references to `pthread_mutex_unlock' follow
# /usr/lib/libgcrypt.a(libgcrypt_la-ath.o): In function `_gcry_ath_mutex_lock':
# /usr/src/libgcrypt-1.6.3/src/ath.c:338: undefined reference to `pthread_mutex_lock'
# /usr/lib/libgcrypt.a(libgcrypt_la-ath.o): In function `_gcry_ath_mutex_unlock':
# /usr/src/libgcrypt-1.6.3/src/ath.c:385: undefined reference to `pthread_mutex_unlock'
# collect2: error: ld returned 1 exit status
# Makefile:625: recipe for target 'cryptsetup.static' failed
# Having this essential tool build is so important that a hotfix is justified.
LIBS="$LIBS -lpthread" \
default_build
