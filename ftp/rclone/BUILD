export GOFLAGS="-mod=mod ${GOFLAGS}" &&
export CGO_ENABLED=1 &&

go build -v -trimpath \
         -ldflags "-s -w -X github.com/rclone/rclone/fs.Version=v$VERSION" \
         $MOUNT_TAGS \
         -o rclone .
