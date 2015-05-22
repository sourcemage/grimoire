if [[ $CLUCENE_BRANCH == "stable" ]]; then
  OPTS="--disable-static $OPTS"  &&
  default_build
else
  if [[ $CLUCENE_CONTRIBS == "y" ]]; then
    OPTS="-DBUILD_CONTRIBS=ON -DBUILD_CONTRIBS_LIB=ON $OPTS"
  fi &&
  cmake_build
fi
