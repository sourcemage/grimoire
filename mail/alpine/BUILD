OPTS="--with-system-pinerc=/etc/pinerc --with-c-client-target=slx ${ALPINE_OPTS} $OPTS" &&
default_build &&
if [[ $ALPINE_TOPAL == y ]] ; then
pushd topal-$VERSION3 &&
make_single &&
make &&
make_normal &&
popd
fi
