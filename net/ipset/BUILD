if [[ ${VERSION/.*} == 4 ]]; then
  make PREFIX="$INSTALL_ROOT/usr"
else
  OPTS="$IPSET_OPTS $OPTS" &&
  default_build &&

  if list_find "$IPSET_OPTS" "--with-kmod"; then
    make modules
  fi
fi
