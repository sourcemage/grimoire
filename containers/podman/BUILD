BUILDTAGS="grpcnotrace seccomp selinux exclude_graphdriver_devicemapper containers_image_openpgp" &&
export GOFLAGS="-trimpath -mod=vendor" &&

if is_depends_enabled $SPELL btrfs-progs; then
  BUILDTAGS="$BUILDTAGS btrfs btrfs_installed"
fi &&

if is_depends_enabled $SPELL apparmor; then
  BUILDTAGS="$BUILDTAGS apparmor"
fi &&

make \
  PREFIX="$INSTALL_ROOT"/usr \
  BUILDTAGS="$BUILDTAGS" \
  podman podman-remote rootlessport quadlet &&

if is_depends_enabled $SPELL go-md2man; then
  make PREFIX=/usr docs
fi
