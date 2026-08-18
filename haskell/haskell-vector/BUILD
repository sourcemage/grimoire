# vector.cabal declares a public sublibrary of benchmark helpers that
# depends on tasty; being a library, --disable-benchmarks does not prune
# it and Cabal will not configure without it.  Ask for the library proper.
OPTS="$OPTS lib:vector" &&
default_build
