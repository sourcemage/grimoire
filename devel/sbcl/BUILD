xc=sbcl
for i in ccl clisp gcl; do
  if is_depends_enabled "$SPELL" "$i"; then
    echo "Boostrapping with $i"
    xc="$i"
    break
  fi
done &&

sh make.sh \
  --with-sb-core-compression \
  --prefix="$INSTALL_ROOT"/usr \
  --xc-host="$xc"
