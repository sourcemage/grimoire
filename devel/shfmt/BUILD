export GOROOT="$INSTALL_ROOT"/opt/go \
       GOPROXY='proxy.golang.org,direct' \
       GOCACHE="$SOURCE_DIRECTORY"/.gocache &&
go build -v \
    -ldflags "-X main.version=$VERSION-${PATCHLEVEL:-0}" \
    ./cmd/shfmt &&
if is_depends_enabled "$SPELL" scdoc; then
  scdoc < cmd/shfmt/shfmt.1.scd > shfmt.1
fi
