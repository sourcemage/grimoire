if [ "$SELINUX" == "y" ]; then
   OPTS="$OPTS --enable-selinux"
fi                                              &&

OPTS="$OPTS --with-pid-file=/var/run/hald.pid \
	    --enable-sysfs-carrier --enable-hotplug-map"  &&
default_build
