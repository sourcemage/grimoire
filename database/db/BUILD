patch -p1 < $SCRIPT_DIRECTORY/javafix.diff &&
sedit 's|\(docdir\w*=\w*[^/]*\)/docs|\1/share/doc/db|' dist/Makefile.in &&

OPTS="$OPTS $DB_JSUP $TESTS"  &&

if  [  "$DB_JSUP"  ==  "--enable-java"  ];  then
  if  [  -f  $INSTALL_ROOT/etc/profile.d/java.sh  ];  then
    source  $INSTALL_ROOT/etc/profile.d/java.sh
  else
    message  "${PROBLEM_COLOR}The provider ${SPELL_COLOR}JAVA${DEFAULT_COLOR}" \
             "${PROBLEM_COLOR} is not installed.${DEFAULT_COLOR}"             &&
    return  1
  fi
fi  &&

# this is needed to make db using stuff work on nptl glibc, do _not_ remove it!
if glibc_is_nptl; then
  LDFLAGS="$LDFLAGS -lpthread"
fi &&

cd  build_unix                         &&

../dist/configure  --prefix=$INSTALL_ROOT/usr  \
                   --build=$BUILD              \
                   --enable-compat185          \
                   --enable-dbm                \
                   $OPTS                       &&
make
