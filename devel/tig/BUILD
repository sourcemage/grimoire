MAKEFLAGS="V=1" default_build &&

if is_depends_enabled ${SPELL} asciidoc; then
  local manuals="tig.1 tigmanual.7 tigrc.5" &&

  for manual in $manuals; do
    a2x -v -d manpage -f manpage --asciidoc-opts="-f doc/asciidoc.conf" doc/$manual.adoc
  done
fi
