patch -p1 < $SCRIPT_DIRECTORY/javafix.diff &&
sedit 's|\(docdir\w*=\w*[^/]*\)/docs|\1/share/doc/db|' dist/Makefile.in &&

#  patch -p0 < $SOURCE_CACHE/$SOURCE2 &&
#  patch -p0 < $SOURCE_CACHE/$SOURCE3 &&

#  if echo "$OPTS" | grep -q 'enable-java'; then
OPTS="$OPTS $JSUP $TESTS"
if  [  "JSUP"  ==  "enable-java"  ];  then
  if  [  -z  $JAVA_HOME  ];  then
    if  [  -f  $TRACK_ROOT/etc/profile.d/java.sh  ];  then
      source  $TRACK_ROOT/etc/profile.d/java.sh
    fi
  fi
fi  &&

# this is needed to make db using stuff work on nptl glibc, do _not_ remove it!
if glibc_is_nptl; then
  LDFLAGS="$LDFLAGS -lpthread"
fi &&

cd  build_unix                         &&

../dist/configure  --prefix=$INSTALL_ROOT/usr  \
                   --build=$BUILD              \
                   --enable-dynamic            \
                   --enable-compat185          \
                   $OPTS                       &&
make
