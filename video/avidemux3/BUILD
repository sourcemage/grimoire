if is_depends_enabled $SPELL qt4; then
    PATH="$QT4DIR/bin:$PATH"
fi &&
# Don't pollute /tmp.
sed -i 's,/tmp/log,log,g' bootStrap.bash &&
# We want avidemux3_cli so that the built avidemux3_jobs can
# actually work.
bash bootStrap.bash --with-cli $OPTS
