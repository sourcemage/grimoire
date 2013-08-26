if [ "$NSS_BRANCH" == "DEFAULT" ]; then
  NSS_BRANCH=3.15
fi &&

MAKE_OPTS="BUILD_OPT=1 NSS_USE_SYSTEM_SQLITE=1 NSS_ENABLE_ECC=1" &&

persistent_add MAKE_OPTS &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == "x86_64" ]]; then
  MAKE_OPTS="$MAKE_OPTS USE_64=1"
fi &&

if [[ $NSS_BRANCH == "3.15" ]]; then
  cd $SOURCE_DIRECTORY/nss &&
  MAKE_OPTS="$MAKE_OPTS NSPR_INCLUDE_DIR=/usr/include/nspr USE_SYSTEM_ZLIB=1 ZLIB_LIBS=-lz"
  make_single &&
  make $MAKE_OPTS &&
  make_normal
else
  cd $SOURCE_DIRECTORY/mozilla/security/coreconf &&
  
  echo 'INCLUDES += -I/usr/include/nspr -I$(DIST)/include/dbm' >> headers.mk &&
  
  if [[ $NSS_BRANCH == 3.11 ]]; then
    sedit 's:$(DIST)/lib:/usr/lib/nspr:' location.mk
  fi &&
  
  make_single &&
  
  make $MAKE_OPTS &&
  
  cd ../dbm &&
  
  make $MAKE_OPTS &&
  
  cd ../nss &&
  
  make $MAKE_OPTS &&
  
  make_normal
fi
