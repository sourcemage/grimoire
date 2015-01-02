# Please notice the use of #ifndef PIC under gdbus/dconf-gdbus-thread.c,
# thus disabling these optimizations to prevent failures like:
# dbus.c:(.text.startup+0x2a): undefined reference to `dconf_engine_dbus_init_for_testing'
# /usr/lib/gcc/x86_64-pc-linux-gnu/4.6.3/../../../../x86_64-pc-linux-gnu/bin/ld: gdbus-thread: hidden symbol `dconf_engine_dbus_init_for_testing' isn't defined
disable_pic force &&
default_build
