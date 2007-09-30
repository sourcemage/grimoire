  local FF FileName DB LCK LL                   &&
  persistent_add FB_PREFIX                      &&
  FB_PREFIX=${INSTALL_ROOT}/usr/firebird        &&
  OPTS="${OPTS} ${FB_SS}"                       &&
if [ $$FB_VER != 2.1 ];then
  if spell_ok icu; then
    ICU_FLAGS=`icu-config --ldflags-libsonly`   &&
    LDFLAGS="$LDFLAGS $ICU_FLAGS"
  fi                                            &&
  if spell_ok libedit; then
    LDFLAGS="$LDFLAGS -ledit"
  fi
fi                                            &&
# prepare optional language support
  for LL in $FB_GPRE; do
    if [ $LL != none ]; then
      OPTS="${OPTS} --with-gpre-${LL}"
    fi
  done                                          &&
  OPTS="${OPTS} ${FB_STAT}"                     &&
  LDFLAGS="$LDFLAGS -lpthread"                  &&

  ./configure 				\
	--prefix=$FB_PREFIX 		\
	$OPTS					&&
  make_single                                   &&
if [ $FB_CLIENT == n ]; then
  make                                          &&
# prepare an install image
  cd gen                                        &&
  ./install/makeInstallImage.sh                 &&
#
# fix ownership and permissions
  cd $SOURCE_DIRECTORY/gen/buildroot/$FB_PREFIX &&
  chown -R root:root ./                         &&
  chmod -R uga-w ./                             &&

# Everyone may execute clients
  chmod 0555 bin/*                              &&
# Shell scripts changing security attributes are for root only
  chmod 0500 bin/*.sh                           &&
# Security database
# Nobody besides firebird permitted to even read this file
  chown firebird:firebird security*.fdb         &&
  chmod 0600 security*.fdb                      &&
# all database should be owned by firebird
  for DB in `ls examples/empbuild/*.fdb`
    do
      chmod ug+w $DB                            &&
      chown firebird:firebird $DB
    done
else
  cd gen                                        &&
  make includes                                 &&
  make -f Makefile.boot.gpre                    &&
  make -f Makefile.libfbclient                  &&
  make -f Makefile.client.isql                  &&
# probably need to build gbak and then restore messages and help fdb
#  make -f Makefile.client.gbak                  &&
  cd firebird                                   &&
  FBDEST=../buildroot${FB_PREFIX}/bin              &&
  mkdir -p $FBDEST                              &&
  cp -a bin/isql $FBDEST                        &&
  FBDEST=../buildroot${INSTALL_ROOT}/usr/lib       &&
  mkdir -p $FBDEST                              &&
  cp -a lib/* $FBDEST                           &&
  FBDEST=../buildroot${INSTALL_ROOT}/usr/include   &&
  mkdir -p $FBDEST                              &&
  cp -a include/* $FBDEST
fi                                              &&
make_normal
