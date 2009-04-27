create_group crontab &&
create_account daemon &&

OPTS="--with-daemon_username=daemon \
      --with-daemon_groupname=crontab \
      $CRONIE_OPTS \
      $OPTS" &&

default_build
