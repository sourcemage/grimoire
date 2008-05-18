create_group vlock  &&

if is_depends_enabled $SPELL libcaca
then
   VLOCK_CACA_MODULE="caca.so"
else
   VLOCK_CACA_MODULE=""
fi

./configure --with-modules="all.so new.so nosysrq.so $VLOCK_CACA_MODULE"  &&

if is_depends_enabled $SPELL linux-pam; then
  make PREFIX="$INSTALL_ROOT/usr" AUTH_METHOD=pam USE_PAM=y
else
  make PREFIX="$INSTALL_ROOT/usr" AUTH_METHOD=shadow USE_PAM=n
fi
