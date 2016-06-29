sed -i "/plugin_dir/s;\.;${TRACK_ROOT}/usr/lib/${SPELL};" buildconf/base.ini &&
if is_depends_enabled ${SPELL} python3; then
  PYTHON=python3
else
  PYTHON=python2
fi &&
export PYTHON &&

${PYTHON} uwsgiconfig.py --build core

for plugin in ${OPTS}; do
  ${PYTHON} uwsgiconfig.py --plugin plugins/${plugin} core
done
