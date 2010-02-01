  local FF DB LL                                &&
  persistent_add FB_PREFIX                      &&
  FB_PREFIX=${INSTALL_ROOT}/opt/firebird        &&
  OPTS="${OPTS} ${FB_SS}"                       &&
  make_single                                   &&
# prepare optional language support
  for LL in $FB_GPRE; do
    if [[ $LL != none ]]; then
      OPTS="${OPTS} --with-gpre-${LL}"
    fi
  done                                          &&
  OPTS="${OPTS} ${FB_STAT}"                     &&
  LDFLAGS="$LDFLAGS -lpthread"                  &&
  ./configure                                    \
	--prefix=$FB_PREFIX                      \
	$OPTS                                   &&

# the first stage must be single-threaded
make_single &&
make Makefile.boot.gpre &&
make_normal &&

if [[ $FB_CLIENT == n ]]; then
#  build everything else
  make                                          &&
  cd $SOURCE_DIRECTORY/gen/firebird             &&
# fix ownership and permissions
  chown -R root:root ./                         &&
  chmod -R uga-w ./                             &&
# Everyone may execute clients
  chmod 0555 bin/*                              &&
# Shell scripts changing security attributes are for root only
  chmod 0500 bin/*.sh                           &&
# Security database
  FF=security2.fdb                              &&
  if [[ -e $FB_PREFIX/$FF ]];then
    mv $FF $FF.new
  else
# Nobody except firebird permitted to even read this file
    chown firebird:firebird $FF                 &&
    chmod 0600 $FF
  fi                                            &&
# all database should be owned by firebird
#  cd $SOURCE_DIRECTORY/gen/                     &&
 for DB in `ls examples/empbuild/*.fdb`
  do
    chmod ug+w $DB                              &&
    chown firebird:firebird $DB
  done
else
  make Makefile.libfbclient &&
  make Makefile.client.isql                  
# probably need to build gbak and then restore messages and help fdb
#  make Makefile.client.gbak 
fi
