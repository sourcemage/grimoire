if [[ ${NETHOGS_LIB} == y ]]; then
  make VERSION=${VERSION} LIBVERSION=${VERSION} libnethogs nethogs &&

  if list_find "${LDFLAGS}" "-s"; then
    strip -v src/libnethogs.so.0.8.5
  fi
else
  make VERSION=${VERSION} nethogs
fi
