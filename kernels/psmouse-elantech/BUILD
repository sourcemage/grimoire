cd "$SOURCE_DIRECTORY/src" &&

make -C "$INSTALL_ROOT/usr/src/linux" M=$PWD \
                                      EXTRA_CFLAGS="-DCONFIG_MOUSE_PS2 -DCONFIG_MOUSE_PS2_ELANTECH" \
                                      CONFIG_MOUSE_PS2=m \
                                      CONFIG_MOUSE_PS2_ELANTECH=y \
                                      psmouse.ko
