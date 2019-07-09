if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" ]] ||
   [[ "${SMGL_COMPAT_ARCHS[1]}" == "em64t"  ]] ||
   [[ "${SMGL_COMPAT_ARCHS[1]}" == "alpha"  ]]
then
  sed -i 's:-O2:-fPIC -DPIC &:' $SOURCE_DIRECTORY/Makefile
fi  &&

make
