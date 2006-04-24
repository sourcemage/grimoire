# GraphViz includes a hack that automatically redirects certain font names
# to certain versions of so called URW Postscript fonts. The error that results
# from such redirection is as follows (trailing font name may change):
#   Error: fontconfig: Didn't find expected font family. Perhaps URW Type 1 fonts need installing? : Times-Roman
# This patch removes said hack.
patch -p1 < $SCRIPT_DIRECTORY/no_postscript_alias.diff &&

find -name Makefile.in | while read _LINE; do
  sedit "s|html/info|$SPELL|g" "$_LINE"
done &&
if ! spell_ok tcl; then
  sedit 's|tclsh|#tclsh|g'      tclpkg/gv/Makefile.in &&
  sedit 's|\<gv_\w\+\.man\>||g' tclpkg/gv/Makefile.in
fi &&
default_build
