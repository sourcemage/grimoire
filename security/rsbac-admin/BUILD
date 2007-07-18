#
# There's no headers build target because headers don't need to be
# built. Therefore only run make if headers isn't the only target,
# and remove headers from the argument list to avoid an error.
#
if [[ "${RSBAC_ADMIN_PKGS// }${OPTS// }" != 'headers' ]]
then
  make  PREFIX="$INSTALL_ROOT/usr"  ${RSBAC_ADMIN_PKGS/headers}  $OPTS
fi
