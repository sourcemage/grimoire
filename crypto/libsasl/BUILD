cd ${SOURCE_DIRECTORY} &&
./configure --prefix=/usr \
          --sysconfdir=/etc \
          --localstatedir=/var \
          --mandir=/usr/share/man \
          --infodir=/usr/share/info \
          ${OPTS} &&
pushd lib &&
make &&
popd
