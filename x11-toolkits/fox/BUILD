OPTS="--enable-release \
      --disable-static \
      ${FOX_OPTS} \
      ${OPTS}" &&

if is_depends_enabled $SPELL $(get_spell_provider $SPELL CUPS); then
  CXXFLAGS="-DHAVE_CUPS_H=1 ${CXXFLAGS}" &&
  LDFLAGS="-lcups ${LDFLAGS}"
fi &&

default_build
