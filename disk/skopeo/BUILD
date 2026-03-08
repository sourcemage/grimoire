targets=(bin/skopeo) &&
if is_depends_enabled "$SPELL" go-md2man; then
  targets+=(docs)
fi &&
make "${targets[@]}"
