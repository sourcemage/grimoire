OPTS+=' smack=false tests=unsafe split-usr=true' &&
OPTS+=' split-bin=true' &&
OPTS+=' rootlibdir=/lib' &&
#OPTS+=' halt-path=/sbin reboot-path=/sbin' &&
OPTS+=' default-hierarchy=hybrid' &&
OPTS+=' cgroup-controller=none' &&
#if is_depends_enabled $SPELL simpleinit-msb;then
#  OPTS+=' cgroup-controller=telinit'
#fi &&
OPTS+=' nobody-group=nogroup' &&
OPTS+=' dbussystemservicedir=/etc/dbus-1/system.d'  &&
default_build

