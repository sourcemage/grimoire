export BUILD_OPT=1 &&
export NSS_USE_SYSTEM_SQLITE=1 &&

persistent_add MAKE_OPTS &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == "x86_64" ]]
then
  MAKE_OPTS="USE_64=1"
fi &&

cd $SOURCE_DIRECTORY/mozilla/security/coreconf &&

echo 'INCLUDES += -I/usr/include/nspr -I$(DIST)/include/dbm' >> headers.mk &&

sed -e 's:$(DIST)/lib:/usr/lib/nspr:' -i location.mk &&

make $MAKE_OPTS &&

cd ../dbm &&

make $MAKE_OPTS &&

cd ../nss &&

make $MAKE_OPTS
