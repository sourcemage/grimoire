local BUILDER &&
local BUILDER_OPTS="-j ${MAKE_NJOBS} -C build" &&

if [[ $(get_spell_provider ${SPELL} NINJA-BUILD) == samurai ]]; then
  BUILDER="samu"
else
  BUILDER="ninja"
fi &&

OPTS="${MUON_OPTS} ${OPTS} prefix=${INSTALL_ROOT}/usr buildtype=release" &&

# postpone until stage 3
if list_find "${OPTS}" "samurai=enabled"; then
  list_remove OPTS "samurai=enabled" &&

  local EMBED_SAMURAI="samurai=enabled"
fi &&

# stage 1
CC=cc ./bootstrap.sh build &&

# stage 2
local MUON_SETUP="build/muon setup" &&
local MUON_SETUP_OPTS &&

for MO in $OPTS; do
  MUON_SETUP_OPTS+=" -D${MO}"
done &&

${MUON_SETUP} ${MUON_SETUP_OPTS} build &&

${BUILDER} ${BUILDER_OPTS} &&

# stage3 (optional)
if [ -n "${EMBED_SAMURAI}" ]; then
  MUON_SETUP_OPTS+=" -D${EMBED_SAMURAI}" &&

  list_add OPTS "${EMBED_SAMURAI}" &&

  ${MUON_SETUP} ${MUON_SETUP_OPTS} build &&

  ${BUILDER} ${BUILDER_OPTS}
fi
