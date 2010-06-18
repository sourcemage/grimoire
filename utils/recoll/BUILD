
function set_qt_environment()
{
  if check_if_qt4_provider
  then
    QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
    PATH="$QTDIR/bin/qt4:$PATH"
  else
    [[ -z $QTDIR ]] && source /etc/profile.d/qt.sh
    QTDIR="${QTDIR:-$INSTALL_ROOT/usr}"
  fi
}

set_qt_environment
OPTS="$RECOLL_OPTS $OPTS"
default_build
