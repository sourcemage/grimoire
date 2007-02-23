# fix for 4.2rc4 alpha macro
sedit 's/\[ "\$GCC"=="yes" \]/test "$GCC" = "yes"/' m4/alpha.m4 &&
if [[ $GNUPLOT_SCM == "y" ]]; then
  ./prepare
else
  # also fix configure if not regenerated
  sedit 's/"\$GCC"=="yes"/test "$GCC" = "yes"/' configure
fi &&
default_build
