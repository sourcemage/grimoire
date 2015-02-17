#!/bin/sh

mount -n tmpfs /sys/fs/cgroup -t tmpfs -o defaults,size=4k,mode=755
cd /sys/fs/cgroup
for cgroup in cpuset cpu,cpuacct memory devices freezer net_cls blkio ; do
    mkdir -p "${cgroup}"
    mount -n cgroup "$cgroup" -t cgroup -o defaults,rw,nosuid,nodev,noexec,relatime,${cgroup}
done
cd /
# mount run
mount -o defaults,size=512m -n -t tmpfs tmpfs /run
mkdir -p /run/lock
mkdir -p /run/shm
# mount tmp
mount -o defaults,size=1024m -n -t tmpfs tmpfs /tmp
