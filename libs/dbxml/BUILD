if [ -z $JAVA_HOME ]; then
  if spell_ok j2sdk; then
    JAVA_HOME=/opt/java/j2sdk
  elif spell_ok j2sdk-bin; then
    JAVA_HOME=/usr/lib/j2sdk1.4.1
  fi
  persistent_add JAVA_HOME
fi &&

cd  build_unix                     &&
PATH=$JAVA_HOME/bin:$PATH          &&
../dist/configure  --prefix=/usr   \
                   --build=$BUILD  \
                   $OPTS           &&

make
