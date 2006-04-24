message "${MESSAGE_COLOR}Running autoconf to fix configure \
scripts${DEFAULT_COLOR}"   &&
  cd $SOURCE_DIRECTORY    &&
for TOFIX in connwrap-0.1 firetalk-0.1 kkconsui-0.1 kkstrtext-0.1 kksystr-0.1 \
libgadu-0.1 libicq2000-0.1 libjabber-0.1 libmsn-0.1 libyahoo2-0.1; do
  cd $TOFIX
  autoconf || return 1
  cd ..
done                      &&
  ./configure --prefix=/usr $OPTS  &&
  make
