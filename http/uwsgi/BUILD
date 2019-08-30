OPTS="${UWSGI_OPTS} ${OPTS}" &&

if is_depends_enabled ${SPELL} python3; then
  PYTHON=python3
else
  PYTHON=python2
fi &&

export PYTHON &&

${PYTHON} uwsgiconfig.py --build core
