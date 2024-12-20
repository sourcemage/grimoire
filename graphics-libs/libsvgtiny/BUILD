# FIXME: for some reaon CCACHE_DIR isn't being exported, maybe run_compiler
# or the variable are being overriden by netsurf's buildsystem.
export CCACHE_DIR
OPTS+=" COMPONENT_TYPE=lib-shared"
OPTS+=" PREFIX=$INSTALL_ROOT/usr"
make $OPTS
