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
  $CS_DIGEST \
  $CS_OTP \
  $CS_SRP \
  $CS_ANON \
  $CS_NTLM \
  $CS_APOP \
  --disable-sample \
"

sedit 's|extern sasl_global_callbacks_t global_callbacks;||g'           lib/saslint.h &&
sedit 's|^\(sasl_global_callbacks_t\s\+global_callbacks;\)|static \1|g' lib/server.c  &&
default_build &&

if [[ "$CS_MECH" =~ 'saslauthd' ]]; then
  pushd saslauthd    &&
  make testsaslauthd &&
  popd
fi
