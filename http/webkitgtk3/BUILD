# remove options not supported by ld.gold
LDFLAGS="${LDFLAGS//-Wl,-znoseparate-code}" &&
OPTS="$WEBKIT_OPTS $OPTS -DENABLE_GAMEPAD=false -DENABLE_WEBKIT_LEGACY=off -DCMAKE_SKIP_RPATH=on -DUSE_SYSTEM_MALLOC=on -DPORT=GTK" &&
# Libraries we don't have
OPTS+=' -DUSE_LIBBACKTRACE=NO -DUSE_SYSTEM_SYSPROF_CAPTURE=NO' &&
CXXFLAGS+=' -std=c++17' &&
default_build
