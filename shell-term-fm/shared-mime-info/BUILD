# There is some trouble with parallel build. LFS book contains this hint:
#   If your processor is not a very recent Intel, you may need to use
#   make -j1 for this package.
# This hit was for version 1.9 in 2018.
make_single                          &&
OPTS="$OPTS --disable-update-mimedb" &&
default_build                        &&
make_normal
