export BUILD_OPT=1 &&
export NSS_USE_SYSTEM_SQLITE=1 &&
export NSS_ENABLE_ECC=1 &&

persistent_add MAKE_OPTS &&
if [[ ${SMGL_COMPAT_ARCHS[1]} == "x86_64" ]]
then
  MAKE_OPTS="USE_64=1"
fi &&

cd $SOURCE_DIRECTORY/mozilla/security/coreconf &&

echo 'INCLUDES += -I/usr/include/nspr -I$(DIST)/include/dbm' >> headers.mk &&

if [[ $NSS_BRANCH != 3.12 ]]; then
  sedit 's:$(DIST)/lib:/usr/lib/nspr:' location.mk
fi &&

make_single &&

make $MAKE_OPTS &&

cd ../dbm &&

make $MAKE_OPTS &&

cd ../nss &&

make $MAKE_OPTS &&

make_normal
