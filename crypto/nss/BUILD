export BUILD_OPT=1 &&
export SOURCE_PREFIX=$(pwd) &&

# use our CFLAGS and pre-installed NSPR headers
#echo "OS_CFLAGS += $CFLAGS -I$INSTALL_ROOT/usr/include/nspr" >>coreconf/Linux.mk &&
# error in config.mk point one level too far
#sedit 's|$(CORE_DEPTH)/\.\./dbm|$(CORE_DEPTH)/dbm|g' dbm/src/config.mk &&
# also use pre-installed NSPR libraries: plc4, plds4
#find nss/lib -name Makefile | while read __MAKEFILE; do
#  sedit 's#$(DIST)/lib/$(LIB_PREFIX)\(plc4\|plds4\)\.$(LIB_SUFFIX)#-l\1#g' $__MAKEFILE
#done &&
persistent_add MAKE_OPTS &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == "x86_64" ]]
then
  MAKE_OPTS="USE_64=1"
fi &&

echo "INCLUDES += -I${ROOT}/usr/include/nspr" >> $SOURCE_DIRECTORY/mozilla/security/coreconf/headers.mk  &&

make_single                                     &&

cd $SOURCE_DIRECTORY/mozilla/security/coreconf  &&
make $MAKE_OPTS                                 &&

cd $SOURCE_DIRECTORY/mozilla/security/dbm       &&
make $MAKE_OPTS                                 &&

cd $SOURCE_DIRECTORY/mozilla/security/nss       &&
make $MAKE_OPTS
