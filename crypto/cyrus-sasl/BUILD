if [[ "$CS_MECH" =~ 'saslauthd' ]]; then
  OPTS="$OPTS --with-saslauthd=/var/run/saslauthd"
fi &&

if [[ "$CS_DB" == none ]]; then
  OPTS="$OPTS --with-dblib=none"
fi &&

OPTS="$OPTS \
  $CS_PLAIN \
  $CS_LOGIN \
  $CS_CRAM \
  $CS_SCRAM \
  $CS_DIGEST \
  $CS_OTP \
  $CS_SRP \
  $CS_PASSDSS \
  $CS_ANON \
  $CS_NTLM \
  $CS_APOP \
  --enable-static \
  --disable-sample" &&

make_single   &&
default_build &&

if [[ "$CS_MECH" =~ 'saslauthd' ]]; then
  pushd saslauthd    &&
  make testsaslauthd &&
  popd
fi  &&
make_normal
