OPTS+=" $LEDGER_OPTS" &&
# Fix build with GCC 14 (hopefully remove after 3.3.2)
OPTS+=' -DCMAKE_CXX_STANDARD=14' &&
# Fix build with CMake 4.0 (hopefully remove after 3.3.2)
OPTS+=' -DCMAKE_POLICY_VERSION_MINIMUM=3.5' &&
# Suppress warnings about deprecated feature with boost 1.88 (hopefully remove after 3.3.2)
CXXFLAGS+=' -DBOOST_BIND_GLOBAL_PLACEHOLDERS' &&
cmake_build
