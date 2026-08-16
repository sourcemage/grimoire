cd "$SOURCE_DIRECTORY" &&

# Build-Type is Simple and the tag tarball ships no setup file
printf 'import Distribution.Simple\nmain = defaultMain\n' > Setup.hs &&

# only the executable is wanted, so build it the vanilla way and let it
# keep the ShellCheck library statically instead of registering one
runhaskell Setup.hs configure -O2 --prefix="$INSTALL_ROOT/usr" \
                              --docdir="$INSTALL_ROOT/usr/share/doc/$SPELL" &&
runhaskell Setup.hs build -j${MAKE_NJOBS}
