OPTS+=" -DNB_TEST=OFF" &&
OPTS+=" -DNB_CREATE_INSTALL_RULES=ON" &&
# use the robin-map spell, not the git submodule (absent from the tarball)
OPTS+=" -DNB_USE_SUBMODULE_DEPS=OFF" &&
# install as a Python package, as pip does, so that
# 'python3 -m nanobind --cmake_dir' finds the CMake files
OPTS+=" -DNB_INSTALL_DATADIR=$(python3 -c 'import sysconfig; print(sysconfig.get_path("purelib"))')/nanobind" &&
default_build
