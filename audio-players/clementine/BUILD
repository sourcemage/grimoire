# XXX fails to link with --as-needed due to a dependency of protobuf on zlib
LDFLAGS="${LDFLAGS//-Wl,--as-needed}" &&
default_build
