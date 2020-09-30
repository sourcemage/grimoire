unset JAVA_HOME &&
cd "$SOURCE_DIRECTORY" &&

NOWARN="-Wno-error=stringop-truncation"    &&
NOWARN+=" -Wno-error=format-overflow"      &&
NOWARN+=" -Wno-error=class-memaccess"      &&
NOWARN+=" -Wno-error=stringop-overflow"    &&
NOWARN+=" -Wno-error=implicit-fallthrough" &&
NOWARN+=" -Wno-error=cast-function-type"   &&
NOWARN+=" -Wno-error=missing-attributes"   &&
NOWARN+=" -Wno-error=format-truncation"    &&

export PATH="$SOURCE_DIRECTORY/jdk-${XVERSION}-ojdkbuild-linux-x64/bin:$PATH" &&

AUTOCONF=/usr/bin/autoconf bash configure \
  --with-vendor-name="Source Mage GNU/Linux" \
  --with-vendor-url="http://www.sourcemage.org" \
  --with-vendor-bug-url="http://bugs.sourcemage.org" \
  --with-extra-cflags="$CFLAGS $NOWARN" \
  --with-extra-cxxflags="$CXXFLAGS $NOWARN" \
  --with-extra-ldflags="$LDFLAGS" \
  --with-num-cores="$MAKE_NJOBS" \
  --with-stdc++lib=dynamic \
  --with-jvm-features=zgc \
  --enable-unlimited-crypto \
  --disable-warnings-as-errors \
  $OPTS --with-memory-size=1024 &&

make -j1 images legacy-jre-images
