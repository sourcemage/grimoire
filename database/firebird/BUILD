  persistent_add FB_PREFIX                      &&
  FB_PREFIX=${INSTALL_ROOT}/usr/firebird        &&
  OPTS="${OPTS} ${FB_SS}"                       &&
  if spell_ok icu; then
    ICU_FLAGS=`icu-config --ldflags-libsonly`   &&
    LDFLAGS="$LDFLAGS $ICU_FLAGS"
  fi                                            &&
  if spell_ok libedit; then
    LDFLAGS="$LDFLAGS -ledit"
  fi                                            &&
  LDFLAGS="$LDFLAGS -lpthread"                  &&

  ./configure 				\
	--prefix=$FB_PREFIX 		\
	$OPTS					&&
  make                                          &&
# prepare an install image
  cd gen                                        &&
  ./install/makeInstallImage.sh

