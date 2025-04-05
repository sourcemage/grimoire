export GOROOT="$INSTALL_ROOT"/opt/go \
       GOPROXY='proxy.golang.org,direct' \
       GOCACHE="$SOURCE_DIRECTORY"/.gocache &&
mkdir bin &&
go build -ldflags "-X main.Version=$VERSION" -o bin ./cmd/...
