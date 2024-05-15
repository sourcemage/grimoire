create_account clamav &&


if is_depends_enabled $SPELL musl-fts; then
  LDFLAGS+=" -lfts"
fi  &&
OPTS+=' -DENABLE_TESTS=off'
cmake_build
