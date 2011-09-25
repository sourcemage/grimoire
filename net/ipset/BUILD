if [[ ${VERSION/.*} == 4 ]]; then
  make PREFIX="$INSTALL_ROOT/usr"
else
  ./autogen.sh &&

  default_build &&
  make modules
fi
