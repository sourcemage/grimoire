OPTS="--with-gdk-pixbuf" &&

case $VERSION in
  2002-05-02) sedit "s/(eval-when-compile (require 'sawfish.wm.commands.xterm))/(require 'sawfish.wm.commands.xterm)/" \
                lisp/sawfish/wm/gnome/integration.jl
              ;;
esac &&

default_build
