# zita-convolver external spelly may come... but that project seems troubled
OPTS="$OPTS --includeresampler --includeconvolver" &&
# This depends on waf_build magically inserting CXXFLAGS.
# Appending to $OPTS does not work because of spaces in $CXXFLAGS ...
force_dialect gnu++11 &&
waf_build
