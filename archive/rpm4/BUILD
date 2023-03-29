OPTS+=' --disable-openmp' &&
case "$BUILD" in
  (*-musl)
    if is_depends_enabled "$SPELL" gettext; then
      LDFLAGS+=' -lintl'
    fi
    ;;
esac &&
default_build
