if is_depends_enabled $SPELL linux-pam; then
  make PREFIX="$INSTALL_ROOT/usr" AUTH_METHOD=pam USE_PAM=y
else
  make PREFIX="$INSTALL_ROOT/usr" AUTH_METHOD=shadow USE_PAM=n
fi
