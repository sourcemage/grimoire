export CGO_CFLAGS="$CFLAGS"              &&
export CGO_CXXFLAGS="$CXXFLAGS"          &&
export CGO_LDFLAGS="$LDFLAGS"            &&
export GOPATH="$SOURCE_DIRECTORY/go"     &&
export GOMODCACHE="$GOPATH"/pkg/mod      &&
export GOENV="$GOPATH"/env               &&
export GOCACHE="$SOURCE_DIRECTORY"/cache &&

go build -mod=readonly -v -work -o bin/packer
