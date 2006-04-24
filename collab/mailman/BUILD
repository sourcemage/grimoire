persistent_add  MAILMAN_CONF  MAILMAN_PREFIX  &&

MAILMAN_SPOOL=/var/spool/mailman   &&
MAILMAN_CONF=/etc/mailman          &&
MAILMAN_PREFIX=/usr/share/mailman  &&

function mk_mailman_dir() {
  local DIRECTORY=$1            &&
  local TAG=${2:-unclassified}  &&

  message "${MESSAGE_COLOR}Preparing ${TAG} directory ${DIRECTORY}${DEFAULT_COLOR}"  &&
  if [[ ! -d $DIRECTORY ]]; then mkdir -p $DIRECTORY; fi  &&
  chown -R mailman.mailman $DIRECTORY                   &&
  chmod -R a+rx,g+ws $DIRECTORY
}

create_account  mailman  &&

sedit  's: -f $(PACKAGEDIR)/mm_cfg.py: -e $(PACKAGEDIR)/mm_cfg.py:' Mailman/Makefile.in &&

# This has to happen before 'configure' otherwise it fails
mk_mailman_dir $MAILMAN_SPOOL 'spool' &&

./configure  --build=$BUILD           \
            --prefix=$MAILMAN_PREFIX  \
   --with-var-prefix=$MAILMAN_SPOOL   \
      --with-cgi-gid=nogroup          \
                     $OPTS            &&
make_single  &&
make
