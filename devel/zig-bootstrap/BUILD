BUILDX="${BUILD//-pc/}" &&
BUILDX="${BUILDX/i686/i386}" &&

CXXFLAGS="${CXXFLAGS//-DPIC}" &&
disable_pic force &&
cd "${SOURCE_DIRECTORY}" &&

if [[ $(get_spell_provider $SPELL NINJA-BUILD) == "ninja-build-system" ]]; then
  CMAKE_GENERATOR=Ninja ./build ${BUILDX} $(uname -m)
elif [[ $(get_spell_provider $SPELL NINJA-BUILD) == "samurai" ]]; then
  CMAKE_GENERATOR=Ninja CMAKE_MAKE_PROGRAM=samu ./build ${BUILDX} $(uname -m)
else
  CMAKE_BUILD_PARALLEL_LEVEL="$MAKE_NJOBS" ./build ${BUILDX} $(uname -m)
fi
