export LIBS &&

case "$HOST" in
(*-musl)
  LIBS+=' -liconv'
  ;;
esac &&

default_build
