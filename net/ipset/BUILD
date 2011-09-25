if [[ ${VERSION/.*} == 4 ]]; then
  make
else
  ./autogen.sh &&

  default_build &&
  make modules
fi
