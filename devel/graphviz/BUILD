find -name Makefile.in | while read _LINE; do
  sedit "s|html/info|$SPELL|g" "$_LINE"
done &&
if ! spell_ok tcl; then
  sedit 's|tclsh|#tclsh|g'      tclpkg/gv/Makefile.in &&
  sedit 's|\<gv_\w\+\.man\>||g' tclpkg/gv/Makefile.in
fi &&
default_build
