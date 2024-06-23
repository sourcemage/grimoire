# Disable Conan, sometimes it fails to build
OPTS+=" -Daudacity_conan_enabled=OFF" &&
# Prevent untracked dependencies.
OPTS+=" -Daudacity_lib_preference=local" &&
cmake_build
