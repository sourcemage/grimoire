# Dependency hell demands C++11.
CXXFLAGS+=" -std=gnu++11" &&
if is_version_less 0.57 "$(installed_version poppler)"; then
  CPPFLAGS+=" -DPOPPLER_NEW_OBJECT_API=1"
fi &&
default_build
