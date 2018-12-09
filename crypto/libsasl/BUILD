cd ${SOURCE_DIRECTORY} &&
for AUTH in `echo ${SASL_AUTH}` ;do
  OPTS+=" --enable-$AUTH"
done &&
echo opts-$OPTS &&
default_build
