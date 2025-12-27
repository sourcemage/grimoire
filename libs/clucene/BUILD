# fix build with cmake 4.2; needed for clucene 2.3.3.4
OPTS+=" -DCMAKE_POLICY_VERSION_MINIMUM=3.5" &&
if [[ $CLUCENE_CONTRIBS == "y" ]]; then
  OPTS="-DBUILD_CONTRIBS=ON -DBUILD_CONTRIBS_LIB=ON $OPTS"
fi &&
cmake_build
