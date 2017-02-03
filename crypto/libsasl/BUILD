cd ${SOURCE_DIRECTORY} &&
for AUTH in `echo ${SASL_AUTH}` ;do
  OPTS+=" --enable-$AUTH"
done &&
echo opts-$OPTS &&
default_build
if(false);then
./configure --prefix=/usr \
          --sysconfdir=/etc \
          --localstatedir=/var \
          --mandir=/usr/share/man \
          --infodir=/usr/share/info \
          ${OPTS} &&
pushd lib &&
make &&
popd
fi
