OPTS="$BIND_CAPS  \
      $BIND_IPV6  \
      --without-libjson \
      $OPTS"      &&

if ! is_depends_enabled "$SPELL" python-sphinx; then
  OPTS+=' ac_cv_path_SPHINX_BUILD=:'
fi &&

create_account  bind  &&
# old iso had a wrongly created bind user, never added to bind group
usermod   bind  -G  bind  2>/dev/null 

./configure  --prefix=/usr           \
             --sysconfdir=/etc/bind  \
             --localstatedir=/var    \
             $OPTS                   &&

make_single  &&
make
