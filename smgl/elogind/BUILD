# Fails to build with -Ofast
CFLAGS="${CFLAGS//-Ofast/-O2}" &&

OPTS="smack=false tests=unsafe split-usr=true split-bin=true
  default-hierarchy=hybrid nobody-group=nogroup ${OPTS}" &&

case $(get_spell_provider ${SPELL} INIT) in
          openrc) OPTS="cgroup-controller=openrc ${OPTS}"  ;;
  simpleinit-msb) OPTS="cgroup-controller=telinit ${OPTS}" ;;
         systemd) OPTS="cgroup-controller=systemd ${OPTS}" ;;
               *) OPTS="cgroup-controller=none ${OPTS}"    ;;
esac &&
#
# special functions for projects which use meson build system

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
  MESON_BUILD="meson setup" &&
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
  MESON_OPTS="-D${MO} ${MESON_OPTS}"
done &&

cd "${SOURCE_DIRECTORY}" &&

${MESON_BUILD} ${MESON_OPTS} builddir/ &&

${BUILDER} ${BUILDER_OPTS}
