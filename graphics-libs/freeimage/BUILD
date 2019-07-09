if [[ "${SMGL_COMPAT_ARCHS[1]}" == "x86_64" || "${SMGL_COMPAT_ARCHS[1]}" == "em64t" ]];  then
  sed -i 's:COMPILERFLAGS = :&-fPIC -DPIC :' $SOURCE_DIRECTORY/Makefile.fip
fi  &&

cd $SOURCE_DIRECTORY  &&
CXXFLAGS+=" -fpermissive -Wno-narrowing" make                  &&
make -f Makefile.fip
