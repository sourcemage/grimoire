# needed else fails to find the dynamic loader
if is_depends_enabled $SPELL lua ; then
CXXFLAGS="-ldl $CXXFLAGS"
fi &&
default_build
