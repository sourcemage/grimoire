OPTS+=" static-libsystemd=true"                           &&
OPTS+=" static-libudev=true"                              &&
OPTS+=" blkid=true"                                       &&
OPTS+=" default-dnssec=no"                                &&
OPTS+=" firstboot=false"                                  &&
OPTS+=" install-tests=false"                              &&
OPTS+=" ldconfig=false"                                   &&
OPTS+=" man=auto"                                         &&
OPTS+=" sysusers=false"                                   &&
OPTS+=" rpmmacrosdir=no"                                  &&
OPTS+=" b_lto=false"                                      &&
OPTS+=" homed=false"                                      &&
OPTS+=" userdb=false"                                     &&
OPTS+=" mode=release"                                     &&
OPTS+=" bpf-framework=false"                              &&
OPTS+=" pamconfdir=${INSTALL_ROOT}/etc/pam.d"             &&
OPTS+=" docdir=${INSTALL_ROOT}/usr/share/doc/systemd-${VERSION}"

OPTS+=" $SYSTEMD_BINFMT"    &&
OPTS+=" $SYSTEMD_ACL"       &&
OPTS+=" $SYSTEMD_EFI"       &&
OPTS+=" $SYSTEMD_HOSTNAMED" &&
OPTS+=" $SYSTEMD_TIMEDATED" &&
OPTS+=" $SYSTEMD_LOCALED"   &&

create_group audio  &&
create_group cdrom  &&
create_group dialout  &&
create_group disk  &&
create_group input  &&
create_group kmem  &&
create_group kvm  &&
create_group lp  &&
create_group render  &&
create_group tape  &&
create_group tty  &&
create_group video  &&

create_group systemd-journal  &&
create_account systemd-journal  &&

create_group systemd-network  &&
create_account systemd-network  &&

create_group systemd-resolve  &&
create_account systemd-resolve  &&

create_group systemd-coredump  &&
create_account systemd-coredump  &&

create_group systemd-oom  &&
create_account systemd-oom  &&

create_group systemd-timesync  &&
create_account systemd-timesync  &&

default_build
