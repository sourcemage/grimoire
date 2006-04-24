OPTS="$BIND_CAPS  \
      $OPTS"      &&

create_account  bind  &&
# old iso had a wrongly created bind user, never added to bind group
usermod   bind  -G  bind  2>/dev/null 

./configure  --prefix=/usr           \
             --sysconfdir=/etc/bind  \
             --localstatedir=/var    \
             $OPTS                   &&

make_single  &&
make
