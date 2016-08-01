# Auto-discover Go
export AUTO_GOPATH=1 &&

go get -d &&
go build &&

if list_find "$LDFLAGS" "-s"; then
  strip -v "${SOURCE_DIRECTORY}/sift-${VERSION}"
fi
