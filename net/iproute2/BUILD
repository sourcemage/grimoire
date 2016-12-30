./configure  &&

if ! is_depends_enabled $SPELL iptables; then
  sedit "/^TC_CONFIG_XT/d" Config &&
  sedit "/^TC_CONFIG_XT_OLD/d" Config &&
  sedit "s/TC_CONFIG_NO_XT:=n/TC_CONFIG_NO_XT:=y/" Config
fi &&

if ! is_depends_enabled $SPELL libselinux; then
  sedit "/^HAVE_SELINUX/d" Config
fi &&

if ! is_depends_enabled ${SPELL} db
then
  sedit "/^HAVE_BERKELEY_DB/d" Config &&
  sedit "/ARPDDIR/d" Makefile
fi &&

echo "CFLAGS += -I$INSTALL_ROOT/usr/include/libnl3" >> ip/Makefile &&

if gcc -include netinet/in.h -E - < /dev/null | grep -q IPPROTO_SCTP ; then
  echo "" > sctpfix.h
else
  cat << EOF > sctpfix.h
enum { IPPROTO_SCTP = 132 };
#define IPPROTO_SCTP               IPPROTO_SCTP
EOF
fi  &&

make  &&

# Verify that ip built ok.
if ! test -e ip/ip ; then
  message "${PROBLEM_COLOR}The ip program failed to build.${DEFAULT_COLOR}"
  return 1
fi  &&

if  [  "$BUILD_DOCS"  =  y  ];  then
  cd $SOURCE_DIRECTORY/doc                         &&
  make                                             &&
  mkdir -p ${INSTALL_ROOT}/usr/share/doc/${SPELL}  &&
  cd $SOURCE_DIRECTORY
fi
