if [ "${PAM_DOCS}" == "y" ]; then
  OPTS="docs=enabled ${OPTS}"
fi &&

OPTS="sbindir=${INSTALL_ROOT}/lib/security
    securedir=${INSTALL_ROOT}/lib/security
read-both-confs=true
             ${OPTS}"                         &&

local PREFIX=${PREFIX:-/usr} &&
local MESON_BUILD_TYPE="${MESON_BUILD_TYPE:-release}" &&

local MESON_BUILD &&
local MESON_OPTS &&
local BUILDER &&
local BUILDER_OPTS="-j $((${#DISTCC_HOSTS[*]} * JOBS_PER_HOST + MAKE_NJOBS)) -C builddir/" &&

if [[ $(get_spell_provider ${SPELL} MESON-BUILD) == muon ]]; then
  MESON_BUILD="muon setup" &&

  OPTS="prefix=${INSTALL_ROOT}${PREFIX} buildtype=${MESON_BUILD_TYPE} default_library=shared libdir=${INSTALL_ROOT}/lib ${OPTS}"
else
  MESON_BUILD="meson setup"
  MESON_OPTS="--prefix ${INSTALL_ROOT}${PREFIX} --buildtype ${MESON_BUILD_TYPE} --default-library shared --libdir ${INSTALL_ROOT}/lib"
fi &&

if ! is_depends_enabled ${SPELL} $(get_spell_provider ${SPELL} NINJA-BUILD); then
  BUILDER="muon samu"
elif [[ $(get_spell_provider ${SPELL} NINJA-BUILD) == samurai ]]; then
  BUILDER="samu"
else
  BUILDER="ninja"
fi &&

for MO in $OPTS; do
  MESON_OPTS+=" -D${MO}"
done &&

cd "${SOURCE_DIRECTORY}" &&

${MESON_BUILD} ${MESON_OPTS} builddir/ &&

${BUILDER} ${BUILDER_OPTS}
