# Do not compile/install su, coreutils provides that
# Bug #4008
patch  -p1  <  ${SCRIPT_DIRECTORY}/su.patch  &&

# Do not install default pam configuration files
sedit 's|pam.d||' etc/Makefile.in  &&

OPTS="$OPTS --enable-shadowgrp --build=${BUILD}" &&
if [[ $CROSS_INSTALL == on ]]; then OPTS="$OPTS --host=${HOST}"; fi &&

./configure --prefix=${TRACK_ROOT}/usr  \
        --sysconfdir=${TRACK_ROOT}/etc  \
     --localstatedir=${TRACK_ROOT}/var  \
            --mandir=${TRACK_ROOT}/usr/share/man   \
           --infodir=${TRACK_ROOT}/usr/share/info  \
                     $OPTS                 &&
make DESTDIR=$INSTALL_ROOT                 &&

# patch login.defs.linux so that spurious messages don't show up during login
if echo $OPTS | grep -q -- '--with-libpam'; then
  sedit '
s|^CHFN_AUTH|#\0|g
s|^CRACKLIB_DICTPATH|#\0|g
s|^ENV_HZ|#\0|g
s|^ENVIRON_FILE|#\0|g
s|^ENV_PATH|#\0|g
s|^ENV_SUPATH|#\0|g
s|^FAILLOG_ENAB|#\0|g
s|^FTMP_FILE|#\0|g
s|^LASTLOG_ENAB|#\0|g
s|^MAIL_CHECK_ENAB|#\0|g
s|^MOTD_FILE|#\0|g
s|^NOLOGINS_FILE|#\0|g
s|^OBSCURE_CHECKS_ENAB|#\0|g
s|^PASS_ALWAYS_WARN|#\0|g
s|^PASS_CHANGE_TRIES|#\0|g
s|^PASS_MIN_LEN|#\0|g
s|^PORTTIME_CHECKS_ENAB|#\0|g
s|^QUOTAS_ENAB|#\0|g
s|^SU_WHEEL_ONLY|#\0|g
' etc/login.defs
else
  sedit '
s|^#MD5_CRYPT_ENAB.*|MD5_CRYPT_ENAB yes|
' etc/login.defs
fi
