sed -i '7326 s,num=`,ver='$(installed_version guile1)'\n&,' configure &&
if [[ $LILYPOND_BRANCH == "stable" ]]; then
  OPTS="$OPTS --with-ncsb-dir=/usr/share/ghostscript/fonts"
else
  OPTS+=" --with-texgyre-dir=$TRACK_ROOT/usr/share/texmf-dist/fonts/opentype/public/tex-gyre"
fi &&
OPTS="$OPTS --disable-documentation" &&
default_build
