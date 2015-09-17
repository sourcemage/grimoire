if is_depends_enabled $SPELL qt4; then
    PATH="$QT4DIR/bin:$PATH"
fi &&
# sudo calls would install stuff right away
sed -i 's:^sudo:# sudo:' bootStrap.sh &&
# For avidemux 2.6, add $OPTS here and switch to .bash .
# The 2.5 build script doesn't know any options.
bash bootStrap.sh
