OPTS="--disable-gpg \
      --disable-gpgsm \
      --disable-scdaemon \
      --disable-tools \
      --disable-doc \
      --disable-nls \
      --docdir=${INSTALL_ROOT}/usr/share/doc/gpg-agent \
      ${OPTS}" &&

default_build &&

cd doc && make gpg-agent.1 && cd ..
