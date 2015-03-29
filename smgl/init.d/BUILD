install -vm 755 -d "$INSTALL_ROOT/etc/init.d/runlevels/%2" &&
touch "$INSTALL_ROOT/etc/init.d/runlevels/%2/sorbus-aria" &&

check_static_dev () {
  echo  "checking if your static /dev is ok..."  &&
  mkdir  /tmp/$$.bindmount                       &&
  mount  --bind  ${INSTALL_ROOT}/  /tmp/$$.bindmount            &&
  cd  /tmp/$$.bindmount/dev                      &&
  if [ ! -c console -o ! -c null ]; then
    message "Ok, going to create!" &&
  # asked in CONFIGURE
  # if query "You don't seem to have a static /dev tree, should i create it ?" y
  # then
    create_group kmem &&
    create_group tty &&
    create_group ppp &&
    create_group lp &&
    create_group disk &&
    create_group floppy &&
    create_group audio &&
    # existing nodes should not make me fail
    $SCRIPT_DIRECTORY/MAKEDEV generic-nopty md || true &&
    mkdir  -p  shm  pts  &&
    mknod  initctl  p || true
  # fi
  else
  echo "seems ok"
  fi                         &&
  cd  /                      &&
  umount  /tmp/$$.bindmount  &&
  rmdir  /tmp/$$.bindmount
}

if  [[ "$DEVICES" != "devfs" ]] && [[ "$CREATE_DEV_TREE" == y ]]; then
  check_static_dev
fi
