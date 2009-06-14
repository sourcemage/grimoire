LISPPROVIDER="$(get_spell_provider $SPELL LISP)"  &&
case "$LISPPROVIDER" in
  clisp)
    OPTS="--enable-clisp  $OPTS" ;;
  sbcl)
    OPTS="--enable-sbcl  $OPTS" ;;
  cmucl)
    OPTS="--enable-cmucl  --with-cmucl-runtime=$INSTALL_ROOT/usr/bin/lisp  $OPTS" ;;
  gcl)
    OPTS="--enable-gcl  $OPTS" ;;
esac  &&
default_build
