if is_depends_enabled vips imagemagick; then
        if is_depends_enabled imagemagick graphviz; then
		LDFLAGS="$LDFLAGS -Wl,--rpath -Wl,/usr/lib/graphviz"
        fi
fi  &&
default_build
