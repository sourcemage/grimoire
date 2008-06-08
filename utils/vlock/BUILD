create_group vlock  &&

if is_depends_enabled $SPELL libcaca
then
   VLOCK_CACA_MODULE="caca.so"
else
   VLOCK_CACA_MODULE=""
fi &&
if is_depends_enabled $SPELL linux-pam; then
  AUTH_METHOD=pam
else
  AUTH_METHOD=shadow
fi &&
# The module path derived from prefix has to work at runtime.
./configure --prefix="/usr" --enable-$AUTH_METHOD --with-modules="all.so new.so nosysrq.so $VLOCK_CACA_MODULE" &&
make
